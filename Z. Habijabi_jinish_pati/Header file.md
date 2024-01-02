```c++
#include <bits/stdc++.h>

#ifndef ONLINE_JUDGE
    #define debug(x)      cerr<< #x << " =  "; _print(x); cerr << endl
    #define bug(...)       __f (#__VA_ARGS__, __VA_ARGS__)
#else
    #define debug(x)
    #define bug(...)
#endif

#define endl  "\n"

using namespace std;


template <typename Arg1>
void __f (const char* name, Arg1&& arg1) { cerr << name << " = " << arg1 << endl; }
template <typename Arg1, typename... Args>
void __f (const char* names, Arg1&& arg1, Args&&... args)
{
    const char* comma = strchr (names + 1, ',');
    cerr.write (names, comma - names) << " = " << arg1 << " | "; __f (comma + 1, args...);
}

// inline void _print(auto x) {cerr << x; }
template <class T> void _print(T x) {cerr << x; }
template <class T, class V> void _print(pair <T, V> p) {cerr << "{"; _print(p.first); cerr << ","; _print(p.second); cerr << "}";}
template <class T> void _print(vector <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(unordered_set <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T> void _print(multiset <T> v) {cerr << "[ "; for (T i : v) {_print(i); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i.second); cerr << " ";} cerr << "]";}
template <class T, class V> void _print(unordered_map <T, V> v) {cerr << "[ "; for (auto i : v) {_print(i.second); cerr << " ";} cerr << "]";}

inline void ErroR () { freopen("Error.txt", "w", stderr);}

```