## Remove consecutive characters:
```c++
    auto last = unique (s.begin(),s.end());
   s.erase(last, s.end()); debug(s);
```

##  Removing specific characters from string:
```c++
    // remove '*' from s
    s.erase(remove(s.begin(), s.end(), '*'), s.end());
```
```c
    The std::remove function in C++ doesn’t actually remove elements from a container. Instead, it rearranges the elements so that all elements that should be “removed” are moved to the end of the container. It then returns an iterator pointing to the first of these “removed” elements.

    However, the size of the container remains unchanged. This means that the “removed” elements are still part of the container, just moved to the end. That’s why we need to call erase after remove to actually delete these elements and reduce the size of the container.
```

## Find vowel in string:
```c++
    string str; cin >> str;
    int vowel = 0;

    for (auto &ch : str) {
        if (string("aeiou").find(ch) + 1) {
            vowel++;
        }
    }
    
```

`Note:` 
```c++
s.find(ch) if ch is not in `s` then it returns npos. And by adding 1 with that [s.find(ch) + 1]  means npos + 1 gives overflow which exceeds the size of size_t datatype hereafter it gives 0 (the starting value of size_t). so, if s.find(ch) + 1 == 0 means ch is not present in string s.

```

## Erase leading zeros in string :
```c++ 
    store.erase(0, store.find_first_not_of('0'));
```
