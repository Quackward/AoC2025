//,                                ________
//,                           +   //////// \
//,           /)  /)                 H   |  +     .
//,         [  ^  ^]      .    +  ___H__ |__ 
//,         // ' v')__ __        ||___|___|_|  +
//,          ~/ \_6/_6     +     |_|_____|_||
//, _____ _  / _) _)     . _____Wv  v _| v  W____,  
// `````````` lm`lm ``````` Clairvoire@gmail.com ```
//   `   `   `   `   `   `  ````````````````````  `
// all code is written by me, feel free to use any of it, 
// (if any of it is even scrutible to you lol)


// --- Boiling Place ---
#define _CRT_SECURE_NO_WARNINGS
#include <cstdint>
#include <cstdarg>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <inttypes.h>
#include <vector>
#include <list>
#include <string>
#include <map>
#include <algorithm>

typedef int64_t    int64;			typedef uint32_t  uint32;	// i32 & u32 -> upto 10^9
typedef int32_t    int32;			typedef uint64_t  uint64;
typedef int16_t    int16;			typedef uint16_t  uint16;	
typedef int8_t     int8;			typedef uint8_t   uint8;   // yeah we are formatting code for vertical length

template <class T> struct vec2_t{T x{0}, y{0};				static uint32 size() {return 2;} T & operator[](uint32 i){return (T*)this + i;} };
template <class T> struct vec3_t{T x{0}, y{0}, z{0};		static uint32 size() {return 3;} T & operator[](uint32 i){return (T*)this + i;} };
template <class T> struct vec4_t{T x{0}, y{0}, z{0}, w{0};	static uint32 size() {return 4;} T & operator[](uint32 i){return (T*)this + i;} };
typedef vec2_t<uint32> u32vec2;		typedef vec2_t<uint64> u64vec2;		typedef vec2_t< int32> i32vec2;		typedef vec2_t< int64> i64vec2;		typedef vec2_t< float>    vec2;
typedef vec3_t<uint32> u32vec3;		typedef vec3_t<uint64> u64vec3;		typedef vec3_t< int32> i32vec3;		typedef vec3_t< int64> i64vec3;		typedef vec3_t< float>    vec3;
typedef vec4_t<uint32> u32vec4;		typedef vec4_t<uint64> u64vec4;		typedef vec4_t< int32> i32vec4;		typedef vec4_t< int64> i64vec4;		typedef vec4_t< float>    vec4;

#define FOR(i, start, end)				for(auto i = (start); i < (end); ++i)
#define FORr(i, start, end)				for(auto i = ((end) - 1u); i >= (start) && i < (end); --i)
#define FORstep(i, start, end, step)	for(auto i = (start); i >= (start) && i < (end); i += step)
#define FOReach(it, contain)			for(auto it = (contain).begin(); it != (contain).end(); ++it)
#define FORreach(it, contain)			for(auto it = (contain).rbegin(); it != (contain).rend(); ++it)
#define SUM(acc, arr, start, end)		FOR(_index, start, end) acc += arr[_index]
#define SUMeach(acc, contain)			FOReach(_iter, contain) acc += _iter
#define PI 3.14159265358979323846
template<class T> bool toMax(T & acc, T next) { return (acc < next) ? (acc = next, true) : (false); }
template<class T> bool toMin(T & acc, T next) { return (acc > next) ? (acc = next, true) : (false); }
template<class T> int toClamp(T & acc, T lower, T upper) { return (acc < lower) ? (acc = lower, -1) : ((acc > upper) ? (acc = upper, 1) : 0); }


//,,, ^^^  end of the boiler place     ^^^ ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//``` vvv  beginning of actual stuff   vvv ``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````


//	   reminders
// - the Law of Puzzles is in effect (remember the cave)
// - invoke the strength of the insane
// - the ghost who haunts the stone is light itself


//     notes
// - 
// -
// -




// day two 
int main_04(int argc, char * argv[]) {
	FILE * file = fopen("advent/puzzle02.txt", "r");
	FILE * vibe = fopen("advent/vibe02.txt", "w");
	uint64 out = 0;
	do {
		uint64 a, b;
		if (2 != fscanf(file, "%llu-%llu,", &a, &b))
			continue;
		fprintf(vibe, "\n%llu\n  vvv  \n", a);
		for (uint64 n = a; n <= b; ++n) {
			uint8 buf[21]; // 21 = max digits in a uint64
			uint32 bufLen;
			uint64 acc = n;
			for (bufLen = 0; bufLen < 21; ++bufLen) {
				buf[bufLen] = acc%10;
				acc /= 10;
				if(acc == 0)
					break;
			}
			++bufLen;
			for (uint32 pivot = 1; pivot <= bufLen / 2; ++pivot) {
				if (bufLen % pivot)
					continue;
				if (buf[0] == buf[pivot]) {
					bool hit = true;
					for (uint32 march = 0; hit && march < bufLen - pivot; march += pivot) {
						for (uint32 i = 0; hit && i < pivot; ++i) {
							if (buf[march + i] != buf[march + i + pivot]) {
								hit = false;
							}
						}
					}
					if (hit) {
						out += n;
						fprintf(vibe, "%llu\n", n);
						break;
					}
				}
			}
		}
		fprintf(vibe, "  ^^^  \n%llu\n", b);
	} while (feof(file) == 0);
	fclose(file);
	fclose(vibe);
	printf("answer is uhh... %llu", out);
	return 0;
}


int main_03(int argc, char * argv[]) {
	FILE * file = fopen("advent/puzzle02.txt", "r");
	FILE * vibe = fopen("advent/vibe02.txt", "w");
	uint64 out = 0;
	do {
		uint64 a, b;
		if (2 != fscanf(file, "%llu-%llu,", &a, &b))
			continue;
		fprintf(vibe, "\n%llu\n  vvv  \n", a);
		for (uint64 n = a; n <= b; ++n) {
			uint8 buf[21]; // 21 = max digits in a uint64
			uint32 bufLen;
			uint64 acc = n;
			for (bufLen = 0; bufLen < 21; ++bufLen) {
				buf[bufLen] = acc%10;
				acc /= 10;
				if(acc == 0)
					break;
			}
			++bufLen;
			if (bufLen & 1)
				continue;
			uint32 pivot = bufLen / 2;
			bool hit = true;
			for (uint32 i = 0; i < pivot; ++i) {
				if (buf[i] != buf[i + pivot]) {
					hit = false;
					break;
				}
			}
			if (hit) {
				out += n;
				fprintf(vibe, "%llu\n", n);
			}
		}
		fprintf(vibe, "  ^^^  \n%llu\n", b);
	} while (feof(file) == 0);
	fclose(file);
	fclose(vibe);
	printf("answer is uhh... %llu", out);
	return 0;
}


// AoC day 1
int main_02(int argc, char * argv[]) {
	FILE * file = fopen("advent/puzzle01.txt", "r");

	const int32 limit = 100;
	uint32 out = 0;
	char sign;
	int32 dist;
	int32 acc = 50;
	do {
		if (2 != fscanf(file, "%c%i\n", &sign, &dist))
			continue;
		if (tolower(sign) == 'r' && dist) {
			int32 rots = (acc + dist) / limit;
			acc += dist;
			out += rots;
			acc %= 100;
		}else if (tolower(sign) == 'l' && dist) {
			if(acc == 0)
				acc = 100;
			int32 rots = -((acc - dist) / limit) + (acc - dist <= 0);
			acc += -dist + limit * rots;
			out += rots;
			acc %= 100;
			if (acc < 0) 
				acc += limit;
		}
	} while (feof(file) == 0);
	fclose(file);
	printf("passphrase is... %u", out);
	return 0;
}


int main_01(int argc, char * argv[]) {
	FILE * file = fopen("advent/puzzle01.txt", "r");
	const int32 limit = 100;
	uint32 out = 0;
	char sign;
	int32 dist;
	int32 acc = 50;
	do {
		if (2 != fscanf(file, "%c%i\n", &sign, &dist))
			continue;
		if (tolower(sign) == 'r') {
			acc += dist;
		}else if (tolower(sign) == 'l') {
			acc -= dist;
		}
		acc %= 100;
		if (acc < 0) 
			acc += limit;
		out += acc == 0;
	} while (feof(file) == 0);
	fclose(file);
	printf("passphrase is... %u", out);
	return 0;
}


