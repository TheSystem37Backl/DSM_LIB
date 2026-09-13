#include "dsm.h"

namespace DSM {
	times statetime;
	const char hChar = '\n';
	const int Standard_Value = 0;
	const char DF = 'D';
	ISN numbers[Standrad_Value_Array];
	ISN matriz_numbers[Standrad_Value_Array][Standrad_Value_Array];
	LSVAR matriz_arraychar[Standrad_Value_Array][Standrad_Value_Array];

	LISN sizes(LSDB Source, LISN limit) {
		if (limit > Standard_Value_LongNumber) return 0;
		LISN retvalue = Standard_Value_numbers;
		for (int i = 0; Source[i] != '\0'; i++) {
			if (retvalue >= Standard_Value_LongNumber) break;
			if (limit > Standard_Value_numbers && retvalue >= limit) break;
			else retvalue++;
		}
		return retvalue;
	}
	void* doublec(double value, enum type_num tr) {
		static int i;
		static char c;
		static short s;
		static long l;
		static long Ll;
		static float f;

		switch (tr) {
		case wINT:
			if (value >= INT_MAX) return 0;
			else if (value <= INT_MIN) return 0;
			else i = (int)value; return &i;

		case wCHAR:
			if (value >= 127) return 0;
			else if (value <= -128) return 0;
			else c = (char)value; return &c;

		case wSHORT:
			if (value >= SHORT_MAX || value <= SHORT_MIN) return 0;
			else s = (short)value; return &s;

		case wLONG:
			if (value >= LONG_MAX || value <= LONG_MIN) return 0;
			else l = (long)value; return &l;

		case wLLONG:
			if (value >= LLONG_MAX || value <= LLONG_MIN) return 0;
			else Ll = (long long)value; return &Ll;

		case wFLOAT:
			f = (float)value; return &f;

		}
		return 0;
	}
	void* _doublec(double value, enum type_num tr) {
		static unsigned int i;
		static unsigned char c;
		static unsigned short s;
		static unsigned long l;
		static unsigned long Ll;
		static float f;

		switch (tr) {
		case wINT:
			if (value >= unsi_INT_LIMIT) return 0;
			else i = (int)value; return &i;

		case wCHAR:
			if (value >= unsi_CHAR_LIMIT) return 0;
			else c = (char)value; return &c;

		case wSHORT:
			if (value >= unsi_SHORT_LIMIT) return 0;
			else s = (short)value; return &s;

		case wLONG:
			if (value >= unsi_LONG_LIMIT) return 0;
			else l = (long)value; return &l;

		case wLLONG:
			if (value >= unsi_LLONG_LIMIT) return 0;
			else Ll = (long long)value; return &Ll;

		case wFLOAT:
			f = (float)value; return &f;

		}
		return 0;
	}

	char* strcpyd(char* dest, const char* src) {
		char* ptr = dest;
		while (*src != '\0') {
			*ptr = *src;
			ptr++;
			src++;
		}
		*ptr = '\0';
		return dest;
	}
	char* strcatd(char* dest, const char* src) {
		char* ptr = dest;
		while (*ptr != '\0') {
			ptr++;
		}
		while (*src != '\0') {
			*ptr = *src;
			ptr++;
			src++;
		}
		*ptr = '\0';
		return dest;
	}

	times wait(LISN times, LISN limit) {
		if (times < 1 || limit < 1) {
			statetime = very_low_price;
			return very_low_price;
		}
		else {
			while (times < limit) {
				statetime = waiting;
				times++;
			}
			statetime = timeout;
			return timeout;
		}
	}
	ISN isBlank(const char* s) {
		for (; *s; s++) {
			if (*s != ' ' && *s != '\r' && *s != '\n' && *s != '\t' && *s != '\v' && *s != '.' && *s != '-' && *s != '_' && *s != '=' && *s != '"') {
				return 0;
			}
		}
		return 1;
	}
	dboolean strdcmd(const char* s1, const char* s2) {
		while (*s1 && *s2) {
			if (*s1 != *s2) return FALSE_;
			s1++;
			s2++;
		}
		return (*s1 == *s2) ? TRUE_ : FALSE_;
	}
	void toUpper(char* s) {
		while (*s) {
			if (*s >= 'a' && *s <= 'z') {
				*s = *s - ('a' - 'A');
			}
			s++;
		}
	}
	LISN lcg(LISN seed, LISN part1, LISN part2, LISN part3) {
		seed = (part1 * seed + part2) % (1u << part3);
		return seed;
	}
	LISN randomBetween(LISN max, LISN part1) {
		return lcg() % (max + part1);
	}
	void toLower(char* s) {
		while (*s) {
			if (*s >= 'A' && *s <= 'Z') {
				*s = *s + ('a' - 'A');
			}
			s++;
		}
	}
	double absolute(double x) {
		return (x < 0) ? -x : x;
	}
	double power(double base, int exp) {
		double result = 1.0;
		bool neg = (exp < 0);
		if (neg) exp = -exp;

		while (exp > 0) {
			if (exp % 2 == 1) result *= base;
			base *= base;
			exp /= 2;
		}
		return neg ? 1.0 / result : result;
	}
	double squareRoot(double x) {
		if (x < 0) return -1;
		double guess = x / 2.0;
		for (int i = 0; i < 20; i++) {
			guess = 0.5 * (guess + x / guess);
		}
		return guess;
	}
	double exponential(double x) {
		double sum = 1.0; // n=0
		double term = 1.0;
		for (int n = 1; n < 20; n++) {
			term *= x / n;
			sum += term;
		}
		return sum;
	}
	double sine(double x) {
		double term = x;
		double sum = x;
		for (int n = 1; n < 10; n++) {
			term *= -x * x / ((2 * n) * (2 * n + 1));
			sum += term;
		}
		return sum;
	}
	double cosine(double x) {
		double term = 1.0;
		double sum = 1.0;
		for (int n = 1; n < 10; n++) {
			term *= -x * x / ((2 * n - 1) * (2 * n));
			sum += term;
		}
		return sum;
	}
	double naturalLog(double x) {
		if (x <= 0) return -1; // erro
		double y = (x - 1) / (x + 1);
		double sum = 0.0;
		double term = y;
		for (int n = 0; n < 20; n++) {
			sum += term / (2 * n + 1);
			term *= y * y;
		}
		return 2 * sum;
	}
	int int_double(double value) {
		return (int)value;
	}
	double double_int(int value) {
		return (double)value;
	}
	int arr_double(double value) {
		if (value >= 0) return (int)(value + 0.5);
		else return (int)(value - 0.5);
	}

	ISN stringLength(const char* s) {
		int len = 0;
		while (*s) {
			len++;
			s++;
		}
		return len;
	}
	DISN Sum(DISN a, DISN b) {
		return a + b;
	}
	DISN Sum(DISN a, DISN b, DISN c, DISN d) {
		return a + b + c + d;
	}
	DISN Sub(DISN a, DISN b) {
		return a - b;
	}
	LISN countChar(LSVAR hChar, LSDB hSource) {
		LISN retvalue = 0;
		for (int i = 0; hSource[i] != '\0'; i++) {
			if (hSource[i] == hChar) retvalue++;
		}
		return retvalue;
	}
	void trim(char* s) {
		// Remove espaços do início
		char* start = s;
		while (*start == ' ' || *start == '\t' || *start == '\n' || *start == '\r' || *start == '\v') {
			start++;
		}

		// Move o conteúdo para o início
		char* dst = s;
		while (*start) {
			*dst++ = *start++;
		}
		*dst = '\0';

		// Remove espaços do fim
		char* end = s;
		while (*end) end++;
		end--; // último caractere válido

		while (end >= s && (*end == ' ' || *end == '\t' || *end == '\n' || *end == '\r' || *end == '\v')) {
			*end-- = '\0';
		}
	}
	dboolean startsWith(const char* s, const char* prefix) {
		while (*prefix) {
			if (*s != *prefix) return FALSE_;
			s++;
			prefix++;
		}
		return TRUE_;
	}
	dboolean endsWith(const char* s, const char* suffix) {
		int lenS = 0;
		int lenSuffix = 0;

		// Calcula o tamanho da string principal
		while (s[lenS] != '\0') lenS++;
		// Calcula o tamanho do sufixo
		while (suffix[lenSuffix] != '\0') lenSuffix++;

		// Compara do final para trás
		for (int i = 0; i < lenSuffix; i++) {
			if (s[lenS - lenSuffix + i] != suffix[i]) {
				return FALSE_;
			}
		}
		return TRUE_;
	}
	
	
	char* ExtractNumber(const char* source, char* buffer) {
		int pos = 0;
		for (; *source != '\0'; source++) {
			if (*source >= '0' && *source <= '9') {
				buffer[pos++] = *source;
			}
		}
		buffer[pos] = '\0';
		if (buffer[0] == '\0') return 0;
		else return buffer;
	}
	char* ExtractChar(const char* source, char* buffer, char c) {
		int pos = 0;
		for (; *source != '\0'; source++) {
			if (*source == c) {
				buffer[pos++] = *source;
			}
		}
		buffer[pos] = '\0';
		if (buffer[0] == '\0') return 0;
		else return buffer;
	}
	char* Extractly(const char* source, char* buffer) {
		int pos = 0;
		for (; *source != '\0'; source++) {
			if (*source >= 'a' && *source <= 'z') {
				buffer[pos++] = *source;
			}
			else if (*source >= 'A' && *source <= 'Z') {
				buffer[pos++] = *source;
			}
		}
		buffer[pos] = '\0';
		if (buffer[0] == '\0') return 0;
		else return buffer;
	}
	dboolean _strdcmd(const char* s1, const char* s2) {
		while (*s1 && *s2) {
			if (*s1 != *s2) return FALSE_;
			s1++;
			s2++;
		}
		return (*s1 == *s2) ? TRUE_ : FALSE_;
	}
	LSDB _strcpyd(LSDB dest, LSDB src, int max) {
		int len = sizes(src, max);
		if (len >= max) {
			if (max > 0) { dest[0] = '\0'; return dest; }
			else return 0;
		}
		for (int i = 0; i < len; i++) {
			dest[i] = src[i];
		}
		dest[len] = '\0';
		return dest;
	}
	LSDB _strcatd(LSDB dest, LSDB src, int max) {
		int dlen = sizes(dest, max);
		int slen = sizes(src, max);
		if (dlen + slen >= max) {
			return 0;
		}
		for (int i = 0; i < slen; i++) {
			dest[dlen + i] = src[i];
		}
		dest[dlen + slen] = '\0';
		return dest;
	}
	int isLower(char c) {
		if (c >= 97 && c <= 122) {
			return 1;
		} else {
			return 0;
		}
	}
	int isUpper(char c) {
		if (c >= 65 && c <= 90) {
			return 1;
		} else {
			return 0;
		}
	}
	int isDigit(char c) {
		if (c >= 48 && c <= 57) {
			return 1;
		} else {
			return 0;
		}
	}
	int isLetter(char c) {
		if (c >= 65 && c <= 90 || c >= 97 && c <= 122) {
			return 1;
		} else {
			return 0;
		}
	}
	int isSymbol(char c) {
		if (c >= 33 && c <= 47 || c >= 58 && c <= 64 || c >= 91 && c <= 96 || c >= 123 && c <= 126) {
			return 1;
		} else {
			return 0;
		}
	}
	int isEsSymbol(char c) {
		if (c >= 0 && c <= 31 || c == 127) {
			return 1;
		} else {
			return 0;
		}
	}

	namespace DB {
		
		class int_sum {
		private:
			ISN hValue;
			LISN hSum;

		public:
			int_sum(ISN v = 0) : hValue(v), hSum(v) {}
			ISN getValue() const {
				return hValue + hSum;
			}
			void setValue(ISN value, LISN value_two) {
				hValue = value;
				hSum = value_two;
			}
		};
		class int_sub {
		private:
			ISN hValue;
			LISN hSum;

		public:
			int_sub(ISN v = 0) : hValue(v), hSum(v) {}
			ISN getValue() const {
				return hValue - hSum;
			}
			void setValue(ISN value, LISN value_two) {
				hValue = value;
				hSum = value_two;
			}
		};
		class int_mul {
		private:
			ISN hValue;
			LISN hSum;

		public:
			int_mul(ISN v = 0) : hValue(v), hSum(v) {}
			ISN getValue() const {
				return hValue * hSum;
			}
			void setValue(ISN value, LISN value_two) {
				hValue = value;
				hSum = value_two;
			}
		};

	}
}
