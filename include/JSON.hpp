#ifndef JSON_H
#define JSON_H

#include <string>
#include <unordered_map>
#include <vector>

namespace JSON {
	class Any {
		public:
			virtual ~Any() {}

		protected:
			explicit Any() {}
	};

	class Array : public Any {
		public:
			explicit Array() {}

			std::vector<Any *> array;

			virtual ~Array() {}
	};

	class Boolean : public Any {
		public:
			explicit Boolean(bool boolean) :
				boolean(boolean)
			{}

			const bool boolean;

			virtual ~Boolean() {}
	};

	class Null : public Any {
		public:
			explicit Null() {}

			virtual ~Null() {}
	};

	class Number : public Any {
		public:
			explicit Number(double number) :
				number(number)
			{}

			const double number;

			virtual ~Number() {}
	};

	class Object : public Any {
		public:
			explicit Object() {}

			std::unordered_map<std::string, Any *> object;

			virtual ~Object() {}
	};

	class String : public Any {
		public:
			explicit String(const std::string& string) :
				string(string)
			{}

			const std::string string;

			virtual ~String() {}
	};

	class Undefined : public Any {
		public:
			explicit Undefined() {}

			virtual ~Undefined() {}
	};
} // namespace JSON

#endif // JSON_H
