#ifndef JSON_H
#define JSON_H

#include <cstdint>
#include <string>
#include <unordered_map>
#include <vector>

namespace JSON {
	class Any {
		public:
			virtual ~Any() {}

			virtual std::string stringify() const = 0;
			friend std::ostream& operator<<(std::ostream& out, const Any& value);

		protected:
			explicit Any() {}
	};

	static std::string quote(const std::string& string) {
		std::string quote = "\"";
		const size_t size = string.size();

		for (size_t i = 0; i < size; ++i) {
			const char c = string[i];

			switch (c) {
				case '"':
					quote += "\\\"";
					break;
				case '\\':
					quote += "\\\\";
					break;
				case 0x08:
					quote += "\\b";
					break;
				case 0x0C:
					quote += "\\f";
					break;
				case 0x0A:
					quote += "\\n";
					break;
				case 0x0D:
					quote += "\\r";
					break;
				case 0x09:
					quote += "\\t";
					break;
				default:
					quote += c;
					break;
			}
		}

		quote += '"';
		return quote;
	}

	namespace STRUCTURAL {
		static const char BEGIN_ARRAY = '[';
		static const char BEGIN_OBJECT = '{';
		static const char END_ARRAY = ']';
		static const char END_OBJECT = '}';
		static const char NAME_SEPARATOR = ':';
		static const char VALUE_SEPARATOR = ',';
	} // STRUCTURAL

	class Array : public Any {
		public:
			explicit Array() {}

			std::vector<Any *> array;

			virtual std::string stringify() const {
				std::string value(1, STRUCTURAL::BEGIN_ARRAY);

				const size_t size = this->array.size();
				if (size > 0) {
					value += this->array[0]->stringify();

					for (size_t i = 1; i < size; ++i) {
						value += std::string(1, STRUCTURAL::VALUE_SEPARATOR) + " " + this->array[i]->stringify();
					}
				}

				value += std::string(1, STRUCTURAL::END_ARRAY);
				return value;
			}

			virtual ~Array() {
				const size_t size = this->array.size();

				for (size_t i = 0; i < size; ++i) {
					delete this->array[i];
				}
			}
	};

	class Boolean : public Any {
		public:
			explicit Boolean(bool boolean) :
				boolean(boolean)
			{}

			const bool boolean;

			virtual std::string stringify() const {
				if (this->boolean) {
					return "true";
				} else {
					return "false";
				}
			}

			virtual ~Boolean() {}
	};

	class Null : public Any {
		public:
			explicit Null() {}

			virtual std::string stringify() const {
				return "null";
			}

			virtual ~Null() {}
	};

	class Number : public Any {
		public:
			explicit Number(double number) :
				number(number)
			{}

			const double number;

			virtual std::string stringify() const {
				static const size_t size = 24;
				char str[size] {};
				snprintf(str, size, "%f", this->number);

				return std::string(str);
			}

			virtual ~Number() {}
	};

	class Object : public Any {
		public:
			explicit Object() {}

			std::unordered_map<std::string, Any *> object;

			virtual std::string stringify() const {
				std::string value(1, STRUCTURAL::BEGIN_OBJECT);
				bool rest = false;

				for (const std::pair<const std::string, Any *>& pair : this->object) {
					if (rest) {
						value += std::string(1, STRUCTURAL::VALUE_SEPARATOR) + " ";
					}

					value += quote(pair.first) + std::string(1, STRUCTURAL::NAME_SEPARATOR) + " " + pair.second->stringify();
					rest = true;
				}

				value += std::string(1, STRUCTURAL::END_OBJECT);
				return value;
			}

			virtual ~Object() {
				for (const std::pair<const std::string, Any *>& pair : this->object) {
					delete pair.second;
				}
			}
	};

	class String : public Any {
		public:
			explicit String(const std::string& string) :
				string(string)
			{}

			const std::string string;

			virtual std::string stringify() const {
				return quote(this->string);
			}

			virtual ~String() {}
	};

	static std::string stringify(const Any& value) {
		return value.stringify();
	}

	std::ostream& operator<<(std::ostream& out, const Any& value) {
		out << value.stringify();
		return out;
	}

	static size_t parse(Any **value, const std::string& input, size_t index, size_t size);

	static bool ws(char c) {
		switch (c) {
			case ' ':
			case '\t':
			case '\n':
			case '\r':
				return true;
		}

		return false;
	}

	static size_t literal(Any **value, const std::string& input, size_t index, size_t size) {
		if (index + 3 < size) {
			switch (input[index]) {
				case 'f':
					if (index + 4 < size &&
						input[index + 1] == 'a' &&
						input[index + 2] == 'l' &&
						input[index + 3] == 's' &&
						input[index + 4] == 'e') {
						if (value) {
							*value = new Boolean(false);
						}
						return index + 5;
					}
					break;
				case 'n':
					if (input[index + 1] == 'u' &&
						input[index + 2] == 'l' &&
						input[index + 3] == 'l') {
						if (value) {
							*value = new Null();
						}
						return index + 4;
					}
					break;
				case 't':
					if (input[index + 1] == 'r' &&
						input[index + 2] == 'u' &&
						input[index + 3] == 'e') {
						if (value) {
							*value = new Boolean(true);
						}
						return index + 4;
					}
					break;
			}
		}

		return index;
	}

	template <char c>
	static size_t structural(char *structural, const std::string& input, size_t index, size_t size) {
		while (index < size && ws(input[index])) {
			++index;
		}

		if (index < size && input[index] == c) {
			if (structural) {
				*structural = c;
			}

			++index;
		}

		while (index < size && ws(input[index])) {
			++index;
		}
		return index;
	}

	static uint8_t hexdigit(char c) {
		if ('0' <= c && c <= '9') {
			return c - '0';
		} else if ('A' <= c && c <= 'F') {
			return c - 'A' + 10;
		} else if ('a' <= c && c <= 'f') {
			return c - 'a' + 10;
		}

		return 0;
	}

	static uint16_t point(char a, char b, char c, char d) {
		return hexdigit(a) << 12 | hexdigit(b) << 8 | hexdigit(c) << 4 | hexdigit(d);
	}

	static size_t string(Any **value, const std::string& input, size_t index, size_t size) {
		size_t i = index;
		if (i < size && input[i] == '"') {
			++i;

			std::string str = "";
			while (i < size) {
				char c = input[i];
				switch (c) {
					case '\\':
						if (i + 1 < size) {
							++i;
							c = input[i];

							switch (c) {
								case '"':
								case '\\':
								case '/':
									str += c;
									break;
								case 'b':
									str += (char) 0x08;
									break;
								case 'f':
									str += (char) 0x0C;
									break;
								case 'n':
									str += (char) 0x0A;
									break;
								case 'r':
									str += (char) 0x0D;
									break;
								case 't':
									str += (char) 0x09;
									break;
								case 'u':
									if (i + 4 < size &&
										isxdigit(input[i + 1]) &&
										isxdigit(input[i + 2]) &&
										isxdigit(input[i + 3]) &&
										isxdigit(input[i + 4])) {
										str += point(input[i + 1], input[i + 2], input[i + 3], input[i + 4]);
										i += 4;
									} else {
										return index;
									}
									break;
								default:
									return index;
							}
						} else {
							return index;
						}
						break;
					case '"':
						if (value) {
							*value = new String(str);
						}
						return i + 1;
					default:
						str += c;
						break;
				}

				++i;
			}
		}

		return index;
	}

	static size_t member(String **name, Any **value, const std::string& input, size_t index, size_t size) {
		size_t next = string((Any **) name, input, index, size);
		if (next > index) {
			char c = 0;
			next = structural<STRUCTURAL::NAME_SEPARATOR>(&c, input, next, size);

			if (c && value) {
				next = parse(value, input, next, size);

				if (*value) {
					return next;
				}
			}
		}

		return index;
	}

	static size_t object(Any **value, const std::string& input, size_t index, size_t size) {
		char c = 0;
		size_t next = structural<STRUCTURAL::BEGIN_OBJECT>(&c, input, index, size);

		if (c) {
			Object *object = new Object();

			String *name = (String *) NULL;
			Any *element = (Any *) NULL;
			next = member(&name, &element, input, next, size);
			if (name && element) {
				object->object[name->string] = element;
			} else if (element) {
				delete element;
				element = (Any *) NULL;
			}

			if (name) {
				delete name;
			}

			while (element) {
				name = (String *) NULL;
				element = (Any *) NULL;

				c = 0;
				next = structural<STRUCTURAL::VALUE_SEPARATOR>(&c, input, next, size);
				if (c) {
					next = member(&name, &element, input, next, size);
					if (name && element) {
						if (object->object[name->string]) {
							delete object->object[name->string];
						}

						object->object[name->string] = element;
						delete name;
					} else {
						if (name) {
							delete name;
						}

						if (element) {
							delete element;
						}

						delete object;
						return index;
					}
				}
			}

			c = 0;
			next = structural<STRUCTURAL::END_OBJECT>(&c, input, next, size);

			if (c) {
				if (value) {
					*value = object;
				}
				return next;
			} else {
				delete object;
			}
		}

		return index;
	}

	static size_t array(Any **value, const std::string& input, size_t index, size_t size) {
		char c = 0;
		size_t next = structural<STRUCTURAL::BEGIN_ARRAY>(&c, input, index, size);

		if (c) {
			Array *array = new Array();

			Any *element = (Any *) NULL;
			next = parse(&element, input, next, size);
			if (element) {
				array->array.push_back(element);
			}

			while (element) {
				element = (Any *) NULL;

				c = 0;
				next = structural<STRUCTURAL::VALUE_SEPARATOR>(&c, input, next, size);
				if (c) {
					next = parse(&element, input, next, size);

					if (element) {
						array->array.push_back(element);
					} else {
						delete array;
						return index;
					}
				}
			}

			c = 0;
			next = structural<STRUCTURAL::END_ARRAY>(&c, input, next, size);

			if (c) {
				if (value) {
					*value = array;
				}
				return next;
			} else {
				delete array;
			}
		}

		return index;
	}

	static size_t decimal(const std::string& input, size_t index, size_t size) {
		if (index < size && input[index] == '.') {
			return index + 1;
		}

		return index;
	}

	static size_t digit(const std::string& input, size_t index, size_t size) {
		if (index < size) {
			const char c = input[index];

			if ('1' <= c && c <= '9') {
				return index + 1;
			}
		}

		return index;
	}

	static size_t digits(size_t *value, const std::string& input, size_t index, size_t size) {
		if (value) {
			while (index < size && isdigit(input[index])) {
				++*value;
				++index;
			}
		} else {
			while (index < size && isdigit(input[index])) {
				++index;
			}
		}

		return index;
	}

	static size_t e(const std::string& input, size_t index, size_t size) {
		if (index < size) {
			const char c = input[index];

			if (c == 'e' || c == 'E') {
				return index + 1;
			}
		}

		return index;
	}

	static size_t frac(const std::string& input, size_t index, size_t size) {
		size_t next = decimal(input, index, size);
		if (next > index) {
			size_t value = 0;
			next = digits(&value, input, next, size);

			if (value > 0) {
				return next;
			}
		}

		return index;
	}

	static size_t minus(const std::string& input, size_t index, size_t size) {
		if (index < size && input[index] == '-') {
			return index + 1;
		}

		return index;
	}

	static size_t plus(const std::string& input, size_t index, size_t size) {
		if (index < size && input[index] == '+') {
			return index + 1;
		}

		return index;
	}

	static size_t sign(const std::string& input, size_t index, size_t size) {
		size_t next = minus(input, index, size);
		if (next > index) {
			return next;
		}

		next = plus(input, index, size);
		if (next > index) {
			return next;
		}

		return index;
	}

	static size_t exp(const std::string& input, size_t index, size_t size) {
		size_t next = e(input, index, size);
		if (next > index) {
			next = sign(input, next, size);

			size_t value = 0;
			next = digits(&value, input, next, size);

			if (value > 0) {
				return next;
			}
		}

		return index;
	}

	static size_t zero(const std::string& input, size_t index, size_t size) {
		if (index < size && input[index] == '0') {
			return index + 1;
		}

		return index;
	}

	static size_t integer(const std::string& input, size_t index, size_t size) {
		size_t next = zero(input, index, size);
		if (next > index) {
			return next;
		}

		next = digit(input, index, size);
		if (next > index) {
			return digits((size_t *) NULL, input, next, size);
		}

		return index;
	}

	static size_t number(Any **value, const std::string& input, size_t index, size_t size) {
		size_t next = minus(input, index, size);
		if (next > index) {
			next = integer(input, next, size);

			if (next > index + 1) {
				next = frac(input, next, size);
				next = exp(input, next, size);
				if (value) {
					*value = new Number(std::strtod(input.data() + index, (char **) NULL));
				}
				return next;
			}
		} else {
			next = integer(input, index, size);

			if (next > index) {
				next = frac(input, next, size);
				next = exp(input, next, size);
				if (value) {
					*value = new Number(std::strtod(input.data() + index, (char **) NULL));
				}
				return next;
			}
		}

		return index;
	}

	static size_t any(Any **value, const std::string& input, size_t index, size_t size) {
		size_t next = literal(value, input, index, size);
		if (next > index) {
			return next;
		}

		next = object(value, input, index, size);
		if (next > index) {
			return next;
		}

		next = array(value, input, index, size);
		if (next > index) {
			return next;
		}

		next = number(value, input, index, size);
		if (next > index) {
			return next;
		}

		next = string(value, input, index, size);
		if (next > index) {
			return next;
		}

		return index;
	}

	static size_t parse(Any **value, const std::string& input, size_t index, size_t size) {
		while (index < size && ws(input[index])) {
			++index;
		}

		index = any(value, input, index, size);

		while (index < size && ws(input[index])) {
			++index;
		}
		return index;
	}

	static size_t parse(Any **value, const std::string& input) {
		return parse(value, input, 0, input.size());
	}
} // namespace JSON

#endif // JSON_H
