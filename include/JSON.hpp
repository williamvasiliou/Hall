#ifndef JSON_H
#define JSON_H

#include <cstdint>
#include <sstream>
#include <string>
#include <unordered_map>
#include <vector>

namespace JSON {
	namespace STRUCTURAL {
		static const char BEGIN_ARRAY = '[';
		static const char BEGIN_OBJECT = '{';
		static const char END_ARRAY = ']';
		static const char END_OBJECT = '}';
		static const char NAME_SEPARATOR = ':';
		static const char VALUE_SEPARATOR = ',';
	} // namespace STRUCTURAL

	static const uint8_t TYPE_ARRAY = 1;
	static const uint8_t TYPE_BOOLEAN = 2;
	static const uint8_t TYPE_NULL = 3;
	static const uint8_t TYPE_NUMBER = 4;
	static const uint8_t TYPE_OBJECT = 5;
	static const uint8_t TYPE_STRING = 6;

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

	class Any {
		public:
			virtual inline const uint8_t& is() const noexcept = 0;

			virtual std::ostream& stringify(std::ostream& out) const = 0;
			friend std::ostream& operator<<(std::ostream& out, const Any& value);

			virtual ~Any() {}

		protected:
			explicit Any() {}
	};

	class Array : public Any {
		public:
			explicit Array() {}

			virtual inline const uint8_t& is() const noexcept {
				return TYPE_ARRAY;
			}

			static inline Array *is(const Any *const& value) {
				if (value && value->is() == TYPE_ARRAY) {
					return (Array *) value;
				} else {
					return (Array *) nullptr;
				}
			}

			std::vector<Any *> array;

			template <typename T>
			inline const T *get(size_t i) const noexcept {
				if (i < this->array.size()) {
					return T::is(this->array[i]);
				} else {
					return (T *) nullptr;
				}
			}

			template <typename T>
			size_t get(std::vector<const T *>& vector) const noexcept {
				size_t items = 0;

				const size_t size = this->array.size();
				for (size_t i = 0; i < size; ++i) {
					const T *value = T::is(this->array[i]);
					if (value) {
						vector.push_back(value);
						++items;
					}
				}

				return items;
			}

			template <typename T, typename U>
			size_t get(std::vector<const T *>& vector) const noexcept {
				size_t items = 0;

				const size_t size = this->array.size();
				for (size_t i = 0; i < size; ++i) {
					const T *value = T::is(U::is(this->array[i]));
					if (value) {
						vector.push_back(value);
						++items;
					}
				}

				return items;
			}

			template <typename T, typename U, const T U:: *data>
			size_t get(std::vector<const T *>& vector) const noexcept {
				size_t items = 0;

				const size_t size = this->array.size();
				for (size_t i = 0; i < size; ++i) {
					const U *value = U::is(this->array[i]);
					if (value) {
						vector.push_back(&(value->*data));
						++items;
					}
				}

				return items;
			}

			inline Any *& operator[](size_t i) noexcept {
				return this->array[i];
			}

			inline const Any *const& operator[](size_t i) const noexcept {
				return this->array[i];
			}

			inline size_t size() const noexcept {
				return this->array.size();
			}

			virtual std::ostream& stringify(std::ostream& out) const {
				out << std::string(1, STRUCTURAL::BEGIN_ARRAY);

				const size_t size = this->array.size();
				if (size > 0) {
					Any *value = this->array[0];
					if (value) {
						value->stringify(out);
					}

					for (size_t i = 1; i < size; ++i) {
						out << std::string(1, STRUCTURAL::VALUE_SEPARATOR) << " ";
						value = this->array[i];
						if (value) {
							value->stringify(out);
						}
					}
				}

				out << std::string(1, STRUCTURAL::END_ARRAY);
				return out;
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

			virtual inline const uint8_t& is() const noexcept {
				return TYPE_BOOLEAN;
			}

			static inline Boolean *is(const Any *const& value) {
				if (value && value->is() == TYPE_BOOLEAN) {
					return (Boolean *) value;
				} else {
					return (Boolean *) nullptr;
				}
			}

			const bool boolean;

			virtual std::ostream& stringify(std::ostream& out) const {
				if (this->boolean) {
					out << "true";
				} else {
					out << "false";
				}

				return out;
			}

			virtual ~Boolean() {}
	};

	class Null : public Any {
		public:
			explicit Null() {}

			virtual inline const uint8_t& is() const noexcept {
				return TYPE_NULL;
			}

			static inline Null *is(const Any *const& value) {
				if (value && value->is() == TYPE_NULL) {
					return (Null *) value;
				} else {
					return (Null *) nullptr;
				}
			}

			virtual std::ostream& stringify(std::ostream& out) const {
				out << "null";
				return out;
			}

			virtual ~Null() {}
	};

	class Number : public Any {
		public:
			explicit Number(double number) :
				number(number)
			{}

			virtual inline const uint8_t& is() const noexcept {
				return TYPE_NUMBER;
			}

			static inline Number *is(const Any *const& value) {
				if (value && value->is() == TYPE_NUMBER) {
					return (Number *) value;
				} else {
					return (Number *) nullptr;
				}
			}

			const double number;

			virtual std::ostream& stringify(std::ostream& out) const {
				out << this->number;
				return out;
			}

			virtual ~Number() {}
	};

	class Object : public Any {
		public:
			explicit Object() {}

			virtual inline const uint8_t& is() const noexcept {
				return TYPE_OBJECT;
			}

			static inline Object *is(const Any *const& value) {
				if (value && value->is() == TYPE_OBJECT) {
					return (Object *) value;
				} else {
					return (Object *) nullptr;
				}
			}

			std::unordered_map<std::string, Any *> object;

			template <typename T>
			inline const T *get(const std::string& name) const {
				const auto& pair = this->object.find(name);
				if (pair != this->object.end()) {
					return T::is(pair->second);
				}

				return (T *) nullptr;
			}

			template <typename T, typename U, const T U:: *data>
			inline const T *get(const std::string& name) const {
				const auto& pair = this->object.find(name);
				if (pair != this->object.end()) {
					const U *value = U::is(pair->second);
					if (value) {
						return &(value->*data);
					}
				}

				return (T *) nullptr;
			}

			inline Any *& operator[](const std::string& name) {
				return this->object[name];
			}

			inline const Any *const& operator[](const std::string& name) const {
				return this->object.at(name);
			}

			virtual std::ostream& stringify(std::ostream& out) const {
				out << std::string(1, STRUCTURAL::BEGIN_OBJECT);
				bool rest = false;

				for (const std::pair<const std::string, Any *>& pair : this->object) {
					if (rest) {
						out << std::string(1, STRUCTURAL::VALUE_SEPARATOR) << " ";
					}

					out << quote(pair.first) << std::string(1, STRUCTURAL::NAME_SEPARATOR) << " ";
					if (pair.second) {
						pair.second->stringify(out);
					}
					rest = true;
				}

				out << std::string(1, STRUCTURAL::END_OBJECT);
				return out;
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

			virtual inline const uint8_t& is() const noexcept {
				return TYPE_STRING;
			}

			static inline String *is(const Any *const& value) {
				if (value && value->is() == TYPE_STRING) {
					return (String *) value;
				} else {
					return (String *) nullptr;
				}
			}

			const std::string string;

			static std::string fromCodePoint(uint16_t point) {
				if (point <= 0x7F) {
					return std::string(1, (char) point);
				} else if (point <= 0x7FF) {
					return std::string(1, (char) (0xC0 | ((point >> 6) & 0x1F))) + std::string(1, (char) (0x80 | (point & 0x3F)));
				} else {
					return std::string(1, (char) (0xE0 | ((point >> 12) & 0x0F))) + std::string(1, (char) (0x80 | ((point >> 6) & 0x3F))) + std::string(1, (char) (0x80 | (point & 0x3F)));
				}
			}

			virtual std::ostream& stringify(std::ostream& out) const {
				out << quote(this->string);
				return out;
			}

			virtual ~String() {}
	};

	static inline std::string stringify(const Any& value) {
		std::ostringstream out;
		value.stringify(out);
		return out.str();
	}

	std::ostream& operator<<(std::ostream& out, const Any& value) {
		return value.stringify(out);
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
										str += String::fromCodePoint(hexdigit(input[i + 1]) << 12 | hexdigit(input[i + 2]) << 8 | hexdigit(input[i + 3]) << 4 | hexdigit(input[i + 4]));
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
			auto& data = object->object;

			String *name = (String *) nullptr;
			Any *element = (Any *) nullptr;
			next = member(&name, &element, input, next, size);
			if (name && element) {
				data[name->string] = element;
			} else if (element) {
				delete element;
				element = (Any *) nullptr;
			}

			if (name) {
				delete name;
			}

			while (element) {
				name = (String *) nullptr;
				element = (Any *) nullptr;

				c = 0;
				next = structural<STRUCTURAL::VALUE_SEPARATOR>(&c, input, next, size);
				if (c) {
					next = member(&name, &element, input, next, size);
					if (name && element) {
						const std::string& string = name->string;

						if (data[string]) {
							delete data[string];
						}

						data[string] = element;
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
			auto& data = array->array;

			Any *element = (Any *) nullptr;
			next = parse(&element, input, next, size);
			if (element) {
				data.push_back(element);
			}

			while (element) {
				element = (Any *) nullptr;

				c = 0;
				next = structural<STRUCTURAL::VALUE_SEPARATOR>(&c, input, next, size);
				if (c) {
					next = parse(&element, input, next, size);

					if (element) {
						data.push_back(element);
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
			return digits((size_t *) nullptr, input, next, size);
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
					*value = new Number(std::strtod(input.data() + index, (char **) nullptr));
				}
				return next;
			}
		} else {
			next = integer(input, index, size);

			if (next > index) {
				next = frac(input, next, size);
				next = exp(input, next, size);
				if (value) {
					*value = new Number(std::strtod(input.data() + index, (char **) nullptr));
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

	static Any *parse(const std::string& input) {
		const size_t size = input.size();
		Any *value = (Any *) nullptr;

		if (parse(&value, input, 0, size) == size) {
			return value;
		} else {
			if (value) {
				delete value;
			}

			return (Any *) nullptr;
		}
	}
} // namespace JSON

#endif // JSON_H
