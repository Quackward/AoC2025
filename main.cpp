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

// --- for --------------------
// https://adventofcode.com/2025



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

#define COND_DECR(_x, _min)  (_x) -= ((_x) != (_min))

//,,, ^^^  end of the boiler place     ^^^ ,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,,
//``` vvv  beginning of actual stuff   vvv ``````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````````


//	   reminders
// - the Law of Puzzles is in effect (remember the cave)
// - invoke the strength of the insane
// - the ghost who haunts the stone is light itself

//     notes
// - 





// --- day six  -----------------------------------------------------------------------------------------------
int main_06b(int argc, char * argv[]) {
	// hwhghh thank god I love rewriting text parsers
	FILE * file = fopen("advent/puzzle06.txt", "r");

	// change up the whole thing
	std::vector<char> bitmap;
	uint32 w = 0;
	uint32 h = 0;
	char ch = fgetc(file);
	while (ch != '\n' && !feof(file)) {
		bitmap.push_back(ch);
		ch = fgetc(file);
		++w;
	}
	while (!feof(file)) {
		++h;
		ch = fgetc(file);
		while (ch != '\n' && !feof(file)) {
			bitmap.push_back(ch);
			ch = fgetc(file);
		}
	}
	
	uint64 out = 0;
	uint32 x = 0;
	while (x < w) {
		char op = bitmap[x + (h - 1) * w];
		uint32 span = 1;
		while (span + x < w && bitmap[span + x + (h - 1) * w] == ' ')
			++span;
		if (span + x != w)
			--span; // finicky edge case stuff
		uint64 result = 0;
		for (uint32 dx = 0; dx < span; ++dx) {
			uint64 arg = 0;
			for (uint32 dy = 0; dy < h - 1; ++dy) {
				char px = bitmap[x + dx + dy * w];
				if (px == ' ') 
					continue;
				arg *= 10;
				arg += px - '0';
			}
			if (dx == 0) {
				result = arg;
			} else {
				switch (op) {
				case '+':	result += arg;	break;
				case '*':	result *= arg;	break;
				}
			}
		}
		out += result;
		x += span + 1;
	}				
	fclose(file);						   
	printf("answer is uhh... %llu", out); 
	return 0;
}

int main_06a(int argc, char * argv[]) {
	FILE * file = fopen("advent/puzzle06.txt", "r");
	//FILE * vibe = fopen("advent/vibe06.txt", "w");
	uint64 out = 0;

	// may as well just do both tallies, it's not expensive
	struct Accum {
		uint64 add	{0};
		uint64 mul	{0};
	};
	std::vector<Accum> tally;
	uint32 row = 0;
	uint32 i = 0;

	do {
		// making this work with scanf is too finicky... just gonna raw dog it
		char ch = fgetc(file);
		while(isspace(ch))
			ch = fgetc(file);
		if (isdigit(ch)) {
			do {
				uint32 arg = ch - '0';
				while (isdigit(ch = fgetc(file))) {
					arg *= 10;
					arg += ch - '0';
				}
				if (row == 0) {
					tally.push_back(Accum{arg, arg});
				} else {
					tally[i].add += arg;
					tally[i].mul *= arg;
				}
				while (ch == ' ')
					ch = fgetc(file);
				++i;
			} while (ch != '\n');
			++row;
			i = 0;
		} else {
			// proooolly the operators
			do {
				switch (ch) {
				case '+':
					out += tally[i].add;
					break;
				case '*':
					out += tally[i].mul;
					break;
				}
				ch = fgetc(file);
				while (ch == ' ')
					ch = fgetc(file);
				++i;
			} while (!feof(file) && ch != '\n');
		}
	} while (!feof(file));
	fclose(file);
	//fclose(vibe);
	printf("answer is uhh... %llu", out); 
	return 0;
}


// --- day five  -----------------------------------------------------------------------------------------------
int main_05b(int argc, char * argv[]) {
	// oh it got easier for part two!
	FILE * file = fopen("advent/puzzle05.txt", "r");

	struct Range {
		uint64 a;
		uint64 b;
		bool operator<(const Range & rhs) {return a < rhs.a;}
	};
	std::vector<Range> ranges;
	std::vector<uint64> food;

	Range range;
	bool adding = false;
	while (1) {
		if (adding == false) {
			if (2 != fscanf(file, "%llu-%llu", &range.a, &range.b)) {
				break;
			}
		}
		bool hit = false;
		for (uint32 n = 0; n < ranges.size(); ++n) {
			if (!(range.a > ranges[n].b || range.b < ranges[n].a)) {
				// combine ranges
				// a range might conjoin two different ranges, soooo lets /remove/ the range we made and re-enter it
				hit = true;
				range.a = std::min(range.a, ranges[n].a);
				range.b = std::max(range.b, ranges[n].b);
				ranges.erase(ranges.begin() + n);
				adding = true;
				break;
			}
		}
		if (!hit) {
			adding = false;
			ranges.push_back(range);
		}	
	}
	std::sort(ranges.begin(), ranges.end());

	uint64 out = 0;
	for (uint32 i = 0; i < ranges.size(); ++i) {
		out += ranges[i].b - ranges[i].a + 1;
	}

	fclose(file);                                    
	printf("answer is uhh... %llu", out);
	return 0;
}

int main_05a(int argc, char * argv[]) {
	FILE * file = fopen("advent/puzzle05.txt", "r");
	//FILE * vibe = fopen("advent/vibe05.txt", "w");
	
	struct Range {
		uint64 a;
		uint64 b;
		bool operator<(const Range & rhs) {return a < rhs.a;}
	};
	std::vector<Range> ranges;
	std::vector<uint64> food;
	
	while (1) {
		Range range;
		if (2 != fscanf(file, "%llu-%llu", &range.a, &range.b)) {
			food.push_back(range.a); // lol lmao
			break;
		}
		bool hit = false;
		for (uint32 n = 0; n < ranges.size(); ++n) {
			if (!(range.a >= ranges[n].b + 1 || range.b + 1 <= ranges[n].a)) {
				// combine ranges 
				// (oh they did something tricksy, but I caught them lmao; some of the ranges touch, but don't overlap)
				hit = true;
				ranges[n].a = std::min(range.a, ranges[n].a);
				ranges[n].b = std::max(range.b, ranges[n].b);
				break;
			}
		}
		if (!hit)
			ranges.push_back(range);
	}
	std::sort(ranges.begin(), ranges.end());
	while (1) {
		uint64 x = 0;
		if (1 != fscanf(file, "%llu\n", &x))
			break;
		food.push_back(x);
	}

	uint64 out = 0;
	for (uint32 n = 0; n < food.size(); ++n) {
		bool hit = false;
		for (uint32 i = 0; i < ranges.size(); ++i) {
			if (ranges[i].a > food[n]) 
				break; // if this range didn't have it, none will
			if (ranges[i].b >= food[n]) {
				hit = true;
				printf("%llu\n%llu +%llu\n\n", food[n], ranges[i].a, ranges[i].b - ranges[i].a);
				break;
			}
		}
		out += hit;
	}

	fclose(file);
	//fclose(vibe);
	printf("answer is uhh... %llu", out);
	return 0;
}


// --- day four -----------------------------------------------------------------------------------------------
int main_04b(int argc, char * argv[]) {
	FILE * file = fopen("advent/puzzle04.txt", "r");
	FILE * vibe = fopen("advent/vibe04.txt", "w");
	uint64 out = 0;

	const uint32 LOCK_CNT = 4; // this or higher in the 8 spaces == not death, life??
	uint32 w = 0;
	uint32 h = 0;
	std::vector<uint8> map;
	do {
		char ch = fgetc(file);
		if (ch == '\n') {
			++h;
		} else if (ch == '.' || ch == '@') {
			map.push_back(ch == '@');
			if (h == 0)
				++w;
		}
	} while(!feof(file));

	// prolly a real elegant way to do this but uhhhh
	// ... it's late, I'm gonna just Video Game it; a kernal guy, HP, splash damage, etc

	for (uint32 y = 0; y < h; ++y) {
		for (uint32 x = 0; x < w; ++x) {
			if(map[x + y * w] == 0)
				continue;
			uint32 adjacent = 1; // intrinsic HP of 1 means the LOCK_CNT comparison is now +1 too
			if (y > 0 && x > 0) 	adjacent += map[(x-1) + (y-1)*w] != 0;
			if (y > 0         ) 	adjacent += map[(x  ) + (y-1)*w] != 0;
			if (y > 0 && x+1<w) 	adjacent += map[(x+1) + (y-1)*w] != 0;
			if (         x > 0) 	adjacent += map[(x-1) + (y  )*w] != 0;
			// freespace
			if (         x+1<w) 	adjacent += map[(x+1) + (y  )*w] != 0;
			if (y+1<h && x > 0) 	adjacent += map[(x-1) + (y+1)*w] != 0;
			if (y+1<h         ) 	adjacent += map[(x  ) + (y+1)*w] != 0;
			if (y+1<h && x+1<w) 	adjacent += map[(x+1) + (y+1)*w] != 0;
			map[x + y * w] = adjacent; // hp
		}
	}

	for (uint32 y = 0; y < h; ++y) {
		for (uint32 x = 0; x < w; ++x) {
			if (map[x + y * w] && map[x + y * w] < LOCK_CNT + 1) {
				++out;
				if (y > 0 && x > 0) 	COND_DECR(map[(x-1) + (y-1)*w], 0); // only decr if not 0
				if (y > 0         ) 	COND_DECR(map[(x  ) + (y-1)*w], 0);
				if (y > 0 && x+1<w) 	COND_DECR(map[(x+1) + (y-1)*w], 0);
				if (         x > 0) 	COND_DECR(map[(x-1) + (y  )*w], 0);
				map[x + y*w] = 0; // free(d) space
				if (         x+1<w) 	COND_DECR(map[(x+1) + (y  )*w], 0);
				if (y+1<h && x > 0) 	COND_DECR(map[(x-1) + (y+1)*w], 0);
				if (y+1<h         ) 	COND_DECR(map[(x  ) + (y+1)*w], 0);
				if (y+1<h && x+1<w) 	COND_DECR(map[(x+1) + (y+1)*w], 0);

				// recoils one scanline + one column; this ensures minimal backtracking... in theory?
				// also ensures we are truly done when we hit the end, at least.
				if (y)
					y -= 1;
				if (x)
					x -= 2; // 2 instead of 1 cause FOR incr laziness
			}
		}
	}

	for (uint32 y = 0; y < h; ++y) {
		for (uint32 x = 0; x < w; ++x) {
			fputc(map[x + y*w] == 0 ? '.' : map[x + y*w]+'0', vibe);
		}
		fputc('\n', vibe);
	}

	fclose(file);
	fclose(vibe);
	printf("answer is uhh... %llu", out);
	return 0;
}

int main_04a(int argc, char * argv[]) {
	FILE * file = fopen("advent/puzzle04.txt", "r");
	//FILE * vibe = fopen("advent/vibe04.txt", "w");
	uint64 out = 0;
	
	const uint32 LOCK_CNT = 4; // this or higher in the 8 spaces == death
	uint32 w = 0;
	uint32 h = 0;
	std::vector<uint8> map;
	do {
		char ch = fgetc(file);
		if (ch == '\n') {
			++h;
		} else if (ch == '.' || ch == '@') {
			map.push_back(ch == '@');
			if (h == 0)
				++w;
		}
	} while(!feof(file));
	
	for (uint32 y = 0; y < h; ++y) {
		for (uint32 x = 0; x < w; ++x) {
			if(map[x + y * w] == 0)
				continue;
			uint32 adjacent = 0;
			if (y > 0 && x > 0) 	adjacent += map[(x-1) + (y-1)*w];
			if (y > 0         ) 	adjacent += map[(x  ) + (y-1)*w];
			if (y > 0 && x+1<w) 	adjacent += map[(x+1) + (y-1)*w];
			if (         x > 0) 	adjacent += map[(x-1) + (y  )*w];
			// freespace
			if (         x+1<w) 	adjacent += map[(x+1) + (y  )*w];
			if (y+1<h && x > 0) 	adjacent += map[(x-1) + (y+1)*w];
			if (y+1<h         ) 	adjacent += map[(x  ) + (y+1)*w];
			if (y+1<h && x+1<w) 	adjacent += map[(x+1) + (y+1)*w];

			if (adjacent < LOCK_CNT) {
				out += 1;
			}
		}
	}
	fclose(file);
	//fclose(vibe);
	printf("answer is uhh... %llu", out);
	return 0;
}


// --- day three -----------------------------------------------------------------------------------------------
int main_03b(int argc, char * argv[]) {
	FILE * file = fopen("advent/puzzle03.txt", "r");
	FILE * vibe = fopen("advent/vibe03b.txt", "w");
	uint64 out = 0;
	std::vector<uint8> bank;
	do {
		bank.clear();
		char ch = fgetc(file);
		while(!feof(file) && !isdigit(ch))
			ch = fgetc(file);
		while (!feof(file) && isdigit(ch)) {
			bank.push_back(ch - '0');
			fprintf(vibe, "%c", ch);
			ch = fgetc(file);
		}
		fprintf(vibe, "\n");
		if (bank.size() == 0)
			continue;

		// we're dumb we can do this way more easily lmao
		const uint32 LEN = 12;
		uint8 x[LEN] = {0};
		uint32 ind[LEN] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};
		uint32 lastIndex = -1; // it's coo
		uint64 expandedValue = 0;
		for (uint32 i = 0; i < LEN; ++i) {
			uint32 maxValue = 0;
			uint32 maxIndex = lastIndex + 1;
			for (uint32 n = lastIndex + 1; n < bank.size() - (LEN-i-1); ++n) {
				if (bank[n] > maxValue) {
					maxValue = bank[n];
					maxIndex = n;
				}
			}
			x[i] = maxValue;
			ind[i] = maxIndex;
			expandedValue *= 10;
			expandedValue += maxValue;
			lastIndex = maxIndex;
		}
		out += expandedValue;
		for (uint32 n = 0; n < bank.size(); ++n) {
			bool hit = false;
			for (uint32 i = 0; i < LEN; ++i) {
				if (ind[i] == n) {
					hit = true;
					break;
				}
			}
			fprintf(vibe, hit ? "^" : " ");
		}
		fprintf(vibe,  "%llu -> %llu", expandedValue, out);
		fprintf(vibe, "\n");
	} while(!feof(file));
	fclose(file);
	fclose(vibe);
	printf("answer is uhh... %llu", out);
	return 0;
}

int main_03a(int argc, char * argv[]) {
	FILE * file = fopen("advent/puzzle03.txt", "r");
	FILE * vibe = fopen("advent/vibe03.txt", "w");
	uint64 out = 0;
	std::vector<uint8> bank;
	do {
		bank.clear();
		char ch = fgetc(file);
		while(!feof(file) && !isdigit(ch))
			ch = fgetc(file);
		while (!feof(file) && isdigit(ch)) {
			bank.push_back(ch - '0');
			fprintf(vibe, "%c", ch);
			ch = fgetc(file);
		}
		fprintf(vibe, "\n");
		uint32 a = 0;
		uint32 b = 0;
		uint32 aInd = 0;
		uint32 bInd = 1;
		for (uint32 aa = 0; aa < bank.size(); ++aa) {
			for (uint32 bb = aa+1; bb < bank.size(); ++bb) {
				if (bank[aa] * 10 + bank[bb] > a * 10 + b) {
					a = bank[aa];
					b = bank[bb];
					aInd = aa;
					bInd = bb;
				}
			}
		}
		out += a * 10 + b;
		for (uint32 n = 0; n < bank.size(); ++n) {
			fprintf(vibe, n == aInd || n == bInd ? "^" : " ");
		}
		fprintf(vibe,  "%u -> %llu", a * 10 + b, out);
		fprintf(vibe, "\n");
	} while(!feof(file));
	fclose(file);
	fclose(vibe);
	printf("answer is uhh... %llu", out);
	return 0;
}

// --- day two  -----------------------------------------------------------------------------------------------
int main_02b(int argc, char * argv[]) {
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


int main_02a(int argc, char * argv[]) {
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


// --- day 1  -----------------------------------------------------------------------------------------------
int main_01b(int argc, char * argv[]) {
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


int main_01a(int argc, char * argv[]) {
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


