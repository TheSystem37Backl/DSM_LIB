#pragma once
#ifndef DSM
#define DSM

#define NAMELIB "TheSystem37Backl0 - DSM Library"
#define NAMELIB_SHORT "DSM Library"

#undef hComputer

#define Standard_Value_numbers 0
#define Standard_Value_LongNumber 18446744073709551615
#define Standrad_Value_Array 64

#define unsi_CHAR_LIMIT 255
#define unsi_SHORT_LIMIT 65535
#define unsi_INT_LIMIT 4294967295
#define unsi_LONG_LIMIT 1844674407370951615
#define unsi_LLONG_LIMIT 18446744073709551615
#define CHAR_MIN -128
#define CHAR_MAX 127
#define SHORT_MIN -32768
#define SHORT_MAX 32767
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define LONG_MIN -2147483648
#define LONG_MAX 2147483647
#define LLONG_MIN -9223372036854757808
#define LLONG_MAX 9223372036854775807

#define hNULL 0

typedef unsigned int LISN;
typedef signed int DISN;
typedef int ISN;
typedef char* LSDB;
typedef const char* ILSDB;
typedef char LSVAR;

typedef enum { _true, _false } comun_bool;
enum dboolean { TRUE_, FALSE_ };

enum StateString { different_char, different_string, same_string, same_char };
enum times { timeout, waiting, very_low_price };
enum type_num { wINT, wCHAR, wSHORT, wLONG, wLLONG, wFLOAT };



namespace DSM {

	union Numbers {
		int i1;
		char i2;
		short i3;
		long i4;
		long long i5;
		float i6;
		double i7;
	};

	void* doublec(double value, enum type_num tr);
	void* _doublec(double value, enum type_num tr);
	LSDB _strcpyd(LSDB dest, LSDB src, int max);
	LSDB _strcatd(LSDB dest, LSDB src, int max);
	char* strcatd(char* dest, const char* src);
	char* strcpyd(char* dest, const char* src);
	LISN sizes(LSDB Source, LISN limit = 0);
	times wait(LISN times = Standard_Value_numbers, LISN limit = Standard_Value_numbers);
	ISN isBlank(const char* s);
	dboolean strdcmd(const char* s1, const char* s2);
	void toUpper(char* s);
	LISN lcg(LISN seed = 1, LISN part1 = 1103515245, LISN part2 = 12345, LISN part3 = 31);
	LISN randomBetween(LISN max, LISN part1 = 1);
	void toLower(char* s);
	double absolute(double x);
	double power(double base, int exp);
	double squareRoot(double x);
	double exponential(double x);
	double sine(double x);
	double cosine(double x);
	double naturalLog(double x);
	int int_double(double value);
	double double_int(int value);
	int arr_double(double value);

	ISN stringLength(const char* s);
	DISN Sum(DISN a, DISN b);
	DISN Sum(DISN a, DISN b, DISN c, DISN d);
	DISN Sub(DISN a, DISN b);
	LISN countChar(LSVAR hChar, LSDB hSource);
	void trim(char* s);
	dboolean startsWith(const char* s, const char* prefix);
	dboolean endsWith(const char* s, const char* suffix);
	
	char* ExtractNumber(const char* source, char* buffer);
	char* Extractly(const char* source, char* buffer);
	dboolean _strdcmd(const char* s1, const char* s2);

	int isLower(char c);
	int isUpper(char c);
	int isDigit(char c);
	int isLetter(char c);
	int isSymbol(char c);
	int isEsSymbol(char c);
	namespace DB {
		template <typename D>

		class database_basic1 {
			D value;
		public:
			database_basic1(D v) : value(v) {}
			D getValue() { return value; }
		};
		template <typename K, typename V>
		class database_basic2 {
			K key;
			V value;
		public:
			database_basic2(K c, V b) : key(c), value(b) {}
			K getKey() { return key; }
			V getValue() { return value; }

		};
		template <typename K, typename V>
		class database {
			database_basic2<K, V>* data;
			int ca, tbm;
		public:
			database(int cap = 10) : ca(cap), tbm(0) {
				data = new database_basic2<K, V>[ca];
			}
			~database() { delete[] data; }
			void inset(K key, V value) {
				if (ca == tbm) {
					ca *= 2;
					database_basic2<K, V>* nov = new database_basic2<K, V>[ca];
					for (int i = 0; i < tbm; i++) nov[i] = data[i];
					delete[] data;
					data = nov;
				}
				data[tbm++] = database_basic2<K, V>(key, value);
			}

			V* find(K key) {
				for (int i = 0; i < tbm; i++) {
					if (data[i].getKey() == key) return &data[i].getValue();
				}
				return 0;
			}
		};
	}

	namespace STRUCT {
		struct array1 {
			char Array[Standrad_Value_Array];
		};
		struct database_basic2 {
			char* data;
			short number_data_short;
			long number_data_long;
		};
	}
}

#endif