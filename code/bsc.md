<div class="two-column-grid">
  <div class="column">

## bsc1501

就輸出吧！

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler cout
```cpp!
#include <iostream>

using namespace std;

int main() {
    cout << "Hello world!" << endl;
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## bsc1502

你會發現只有一個情況 Wei 沒辦法到達 Jimmy: 當 $x, y$ 座標都是奇數時，Wei 必須要走兩個短步。

於是這個問題就變成「判定 $x, y$ 是否都是奇數」。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler 運算子 + if 判斷式
```cpp!
#include <iostream>

using namespace std;

int main() {
    int x, y;
    cin >> x >> y;
    if (x % 2 == 1 && y % 2 == 1) {
        cout << "NO" << endl;
    } else {
        cout << "YES" << endl;
    }
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## bsc1503

#### 75%

直接用質數的定義：在 $1$ 到 $n$ 之間只有兩個因數：$1$ 和自己。

於是你就可以用一個 for 迴圈遍歷所有 $1$ 到 $n$ 之間的整數，然後順便計算有幾個數字可以整除 $n$。

#### 95%

這時候，直接用 for 迴圈爆搜就太慢了！

但仔細回想一下，你在數學課是否有聽過或用過一個技巧：

因為因數都是成雙成對的 (例如: $36=1\cdot36=2\cdot18=3\cdot12=4\cdot9=6\cdot6$) 其中一個必 $\le\sqrt n$，另一個必 $\ge\sqrt n$。

因此要檢查一個數字是否為質數，只需要檢查 $n$ 能不能被任何 $1\sim\left\lfloor\sqrt n\right\rfloor$ 的整數整除就好了，你在寫數學題目時，甚至只需要檢查能不能被那個範圍內的質數整除就好了。

一個小細節，for 迴圈的判定請不要用 `sqrt(n)`，~~首先我們沒有教~~，再者以前也強調過浮點數是個很爛的東西，如果你真的想用，請檢查比 `sqrt(n)` 多一些數字。

因此，與其寫 $i\le \sqrt n$，不如把兩邊平方，寫 $i\cdot i\le n$，小數點的問題就迎刃而解了！

如果你不知道要寫 $\le$ 還是 $<$，你可以想一下「質數的平方」的例子，例如 $49$，你必須檢查到 $7|49$ 才能確定它是合數。想簡單一點，多判斷一兩個數字無傷大雅，何必用 $<$ 然少判一個數字苦了自己呢?

最後，記得特判 $1$，它不是質數。

#### 100%

直接破題吧，這東西叫做米勒-拉賓質數篩檢法 ($\text{Miller-Rabin Primality Test}$)，至於實作內容會用到快速冪，超綱了。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler 75%
```cpp!
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, divisors = 0;
        cin >> n;
        for (int i=1;i<=n;i++) {
            if (n % i == 0) {
                divisors++;
            }
        }
        if (divisors == 2) {
            cout << "YES" << endl;
        } else {
            cout << "NO" << endl;
        }
    }
}
```
:::

:::spoiler 95%
```cpp!
#include <iostream>

using namespace std;

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;

        if (n == 1) {
            cout << "NO" << endl;
            continue;
        }

        bool isprime = true;
        for (int i=2;i*i<=n;i++) {
            if (n % i == 0) {
                cout << "NO" << endl;
                isprime = false;
                break;
            }
        }

        if (isprime) {
            cout << "YES" << endl;
        }
    }
}
```
:::

:::spoiler 100%
```cpp!
#include <bits/stdc++.h>
 
using namespace std;

using ull = uint64_t;
using u128 = __uint128_t;

ull fpow(ull a, ull b, ull m) {
    ull res = 1;
    for (a %= m; b; b >>= 1, a = (u128)a * a % m)
        if (b & 1) res = (u128)res * a % m;
    return res;
}

bool comp(ull base, ull p, ull s, ull d) {
    ull res = fpow(base, d, p);
    if (res == 1 or res == p - 1) return false;
    while (--s)
        if ((res = (u128)res * res % p) == p - 1) return false;
    return true;
}

bool millerrabin(ull p) {
    if (p == 1) return false;
    int s = __builtin_ctzll(p - 1);
    ull d = p - 1 >> s;

    for (ull base: {2, 325, 9375, 28178, 450775, 9780504, 1795265022}) {
        if (p == base) return true;
        if (p % base == 0) return false;
        if (comp(base, p, s, d)) return false;
    }
    return true;
}

int main() {
    int t; cin >> t;
    while (t--) {
        ull n; cin>> n;
        cout << (millerrabin(n)? "YES\n": "NO\n");
    }
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## bsc1504

你甚至可以從題目讀出「當...」的字眼，也就是說要用 while 迴圈了。

記得，你可以一邊操作，一邊輸出。

最後，如果你用 `int`，思考一下，只要是一個在 $10^9$ 附近的奇數，只要操作一次乘 $3$ 加 $1$ 就超過 `int` 範圍了，所以請記得改成 `long long`。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler cout
```cpp!
#include <iostream>

using namespace std;

int main() {
    long long n;
    cin >> n;
    while (n != 1) {
        cout << n << ' ';
        if (n % 2 == 0) {
            n /= 2;
        } else {
            n = n * 3 + 1;
        }
    }
    cout << n << '\n';
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## bsc1505

想簡單一點，題目只是想問你 $p$ 的組成字母和 $q$ 是否就剛好相差一個 $``\text{six}"$。

至於實作細節，你可以在一開始輸入完兩個字串後就直接 `q += "six"`。

接下你可以選擇使用兩個長度為 $26$ 的陣列來儲存兩字串中每一個字母出現的次數，最後判斷兩個陣列是否一模一樣就好。或者是說，你可以對兩個字串分別「一加一減」，這樣用一個陣列就可以了，最後就是判定是否每一項都是 $0$。

抑或是你可以偷學怎麼 sort 一個字串，然後 `q += "six` 後就可以無腦 sort 然後判斷兩字串是否相同就好了。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler 計算字母出現頻率
```cpp!
#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    string p, q;
    cin >> p >> q;
    q += "six";

    int frequency_p[26] = {}, frequency_q[26] = {};

    for (int i=0;i<a;i++) {
        frequency_p[p[i]-'A']++;
    }
    for (int i=0;i<b+3;i++) {
        frequency_q[q[i]-'A']++;
    }

    for (int i=0;i<26;i++) {
        if (frequency_p[i] != frequency_q[i]) {
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
}
```
:::

:::spoiler 計算字母出現頻率
```cpp!
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;

    string p, q;
    cin >> p >> q;
    q += "six";

    sort(p.begin(), p.end());
    sort(q.begin(), q.end());

    if (p == q) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
```
:::

  </div>
</div>
