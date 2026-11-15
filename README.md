<style>
.two-column-grid {
  display: grid;
  grid-template-columns: 1fr 1fr;
  gap: 30px;
  margin: 20px 0;
}

.column {
  padding: 0;
}

@media (max-width: 768px) {
  .two-column-grid {
    grid-template-columns: 1fr;
    gap: 20px;
  }
}

.markdown-body, .ui-infobar {
    max-width: unset !important;
}
</style>

# 15th 初階班 (c001~)

<div class="two-column-grid">
  <div class="column">

## c001

就輸出吧！

記得 `#include <iostream>`, `using namespace std;` 要背好，然後 `cout` 的箭頭是向左的 `<<`。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler cout
```cpp!
#include <iostream>

using namespace std;

int main() {
    cout << "hello world!" << endl;
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c002

直接翻譯：

```cpp!
int main() {
    宣告整數變數 a, b;
    依序輸入 a, b;
    輸出 a + b 再換行;
}
```

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler 變數宣告+基本輸入輸出
```cpp!
#include <iostream>

using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    cout << a + b << endl;
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c004

如果用 if 就很直觀了，記得條件式的括號是小括號 `()`，後面的 code 是包在 `{}` 內的。

至於第二個解法，其實就是把布林值當作整數來加減，$\tiny{\text{真的超漂亮的}}$。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler if 判斷式
```cpp!
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    if (n > 0) {
        cout << 1 << endl;
    } else if (n < 0) {
        cout << -1 << endl;
    } else {
        cout << 0 << endl;
    }
}
```
:::
:::spoiler 運算子
```cpp!
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    cout << (n > 0) - (n < 0) << endl;
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c005

這題的 `if` 也蠻直觀的，如果減去 $15$ 會變負數，那就加 $24$ 再減 $15$，也就是加 $9$ 吧。

如果你不想用 if，也可以對 $24$ 取模，但是 C++ 的負數取模(其實是除法)規則和數學抑或是 python 的定義都不太相同，負數取模會是負的，所以保險的做法就是先加上 $24$。

`((n - 15) % 24 + 24) % 24` $\xrightarrow{其實負數不會超過 -24}$ `(n - 15 + 24) % 24` $\rightarrow$ `(n + 9) % 24`

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler if 判斷式
```cpp!
#include <iostream>

using namespace std;

int main(){
    int a;
    cin >> a;
    if (a>=15){
        cout << a - 15 << endl;
    } else {
        cout << a + 9 << endl;
    }
}
```
:::
:::spoiler 取模運算
```cpp!
#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    cout << (n + 9) % 24 << endl;
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c006

直接照著閏年的規則依樣畫葫蘆寫 if 就可以了，但是如果你想用 `!`, `&&` 和 `||` 來合併的話，記得 `||` 的優先順序是比較低的，再來是 `&&`。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler if 判斷式
```cpp!
#include<iostream>

using namespace std;

int main() {
	int n;
	cin>>n;
	if (n % 400 == 0){
	    cout << "閏年" << endl;
	} else if (n % 100 == 0){
	    cout << "平年" << endl;
	} else if (n % 4 == 0) {
	    cout << "閏年" << endl;
    } else {
        cout << "平年" << endl;
    }
}
```
:::
:::spoiler &&, ||
```cpp!
#include <iostream>

using namespace std;

int main() {
    int n; cin>>n;
    if (n % 400 == 0 || n % 100 != 0 && n % 4 == 0) cout<< "閏年" << endl;
    else cout << "平年" << endl;
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c007

這題有很多做法，其中一種是將數字分成奇偶數輸出，$n$ 比較小時數字會黏在一起留意一下就好。

比較漂亮的做法是先輸出偶數再輸出奇數，這樣 $n=4$ 的部分就不需要額外判斷了。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler for 迴圈
```cpp!
#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    if (n == 2 or n == 3) {
        cout << "NO SOLUTION" << endl;
    } else {
        for (int i=2;i<=n;i+=2) {
            cout << i << ' ';
        }
        for (int i=1;i<=n;i+=2) {
            cout << i << ' ';
        }
    }
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c008

你的目標是要組合出「可以往下(上)滑剛好一篇」的方法。

於是你可以試著組出越來越小的篇數的方法，例如你可以往下 $19$ 和往上 $8$ 時，你可以先往下滑一次 $19$ 再往上滑兩次 $8$，於是你就有往下滑 $19-8\cdot2=3$ 篇的能力了。往下滑兩次 $3$ 再往上滑 $8$ 次，你就有往上滑 $2$ 篇的能力了。往下滑一次 $3$ 再往上滑一次 $2$，你就有往下滑 $1$ 篇的能力了。這是個比較不嚴謹的思考過程，當然你還要再組合出往上滑 $1$ 篇的能力，但是想法大致上就是如此。

你會發現這個過程很像輾轉相除法，而要判斷的便是「最大公因數」是否為 $1$。

或者是說你有聽過貝祖定理的話你也可以直接省去這個思考的過程直接秒殺。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler while 迴圈 + 輾轉相除法
```cpp!
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    while (m > 0) {
        int temp = m;
        m = n % m;
        n = temp;
    }

    if (n == 1) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
}
```
:::
:::spoiler [小技巧] std::tie(), std::tuple
```cpp!
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m; cin>>n>>m;
    while (m) tie(n, m) = make_tuple(m, n % m);
    cout << vector<string>{"NO", "YES"}[n == 1] << '\n';
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c009

其實就是在問你 $1\times2\times3\times\dots\times n$ 的質因數分解有幾個 $5$ (不用判斷 $2$ 因為它一定會比 $5$ 多)。

也就是說，你可以先判斷「至少有 $5^1$」的數字有多少個($\left\lfloor\dfrac n5\right\rfloor$)，再判斷「至少有 $5^2$」的數字有多少個($\left\lfloor\dfrac n{5^2}\right\rfloor$)...

偷吃步，你可以每判斷完一次就把 `n /= 5`，這樣每次就除以 $5$ 的一次方就好。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler while 迴圈
```cpp!
#include <iostream>

using namespace std;

int main() {
    long long n, res = 0;
    cin >> n;

    while (n > 0) {
        n /= 5;
        res += n;
    }

    cout << res << endl;
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c010

這題的重點是要用迴圈外的變數來記錄一些重要的數值：目前連續吃幾個蠶豆酥了、目前總共吃了幾個蠶豆酥了、還有我總共有吃了幾個零食。

剩下的，就靠你了，記得善用 `break` 和 `continue`。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler while, break
```cpp!
#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;

    int streak = 0, fava = 0, res = 0;
    while (n--) {
        res++;
        int a;
        cin>>a;
        if (a) {
            streak = 0;
        } else {
            fava++;
            streak++;
            if (streak == 4) {
                break;
            }
        }
    }
    cout << fava << ' ' << res << '\n';
}
```
:::
:::spoiler [小技巧] 前序運算子
```cpp!
#include <iostream>

using namespace std;

int main() {
    int n; cin>>n;

    int streak = 0, fava = 0, res = 0;
    while (n-- && ++res) {
        int a; cin>>a;
        if (a) streak = 0;
        else if (++fava and ++streak == 4) break;
    }
    cout << fava << ' ' << res << '\n';
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c011

一樣，我們要用迴圈外的數字來記錄重要的東西，這次我們多加了：開心度、目前還需要暫停幾輪等等。

各種判斷、操作的順序請小心安排。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler while, break, continue
```cpp!
#include <iostream>

using namespace std;

int main() {
    int good = 0, fava = 0, n, h;
    cin>>n>>h;

    int res = 0, breakdown = 0, limit = 0;
    bool penalty = false;
    while (n--) {
        if (h == 0) break;

        int a;
        cin>>a;

        if (limit) {
            limit--;
            continue;
        }

        if (penalty and !a) {
            h--;
            if (h == 1) {
                limit = 4;
                breakdown++;
                fava = 0;
                penalty = false;
            }
            continue;
        }
        penalty = false;

        if (a) {
            good++;
            fava = 0;
        } else {
            fava++;
            good = 0;
            res++;
        }

        if (fava == 4) {
            penalty = true;
        }
        if (good == 3) {
            good = 0;
            h++;
        }
    }
    cout << breakdown << ' ' << res << '\n';
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c012

主要的考點就是 `while (cin >> ...)`，剩下的其實就是寫完那個超醜的 if 判斷式來幫兩人加分還有判斷 deuce。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler while 迴圈 + if 判斷式
```cpp!
#include <iostream>

using namespace std;

int main() {
    int n; cin>>n;
    int jimmy = 0, wei = 0;
    char a, b;
    while (cin >> a >> b) {
        if (a == b) continue;
        if (a == 'r' and b == 's' or a == 's' and b == 'p' or a == 'p' and b == 'r') {
            jimmy++;
        } else {
            wei++;
        }
        
        if ((wei >= n or jimmy >= n) and (wei - jimmy >= 2 or jimmy - wei >= 2)) {
            break;
        }
    }
    cout << jimmy << ' ' << wei << '\n';
}
```
:::
:::spoiler [小技巧] max / abs 函式
```cpp!
#include <iostream>

using namespace std;

int main() {
    int n; cin>>n;
    int jimmy = 0, wei = 0;
    char a, b;
    while (cin >> a >> b) {
        if (a == b) continue;
        if (a == 'r' and b == 's' or a == 's' and b == 'p' or a == 'p' and b == 'r') jimmy++;
        else wei++;
        
        if (max(wei, jimmy) >= n and abs(wei-jimmy) >= 2) break;
    }
    cout << jimmy << ' ' << wei << '\n';
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c013

我就直接補上推導過程吧。這次用的是迭代式的算法，遞迴的好寫很多但我們的重點是 while 迴圈。

---

我們已經知道 $n, m$ 的值，而最終目的是找到 $x, y$ 使 $nx - my = \gcd(n, m)$，這樣就可以對 $x, y$ 同乘上 $\dfrac k{\gcd(n, m)}$，就找到答案了。

如果 $k$ 是負數，我們就可以對以上式子改成組合出 $-gcd(a, b)$ 的模式:

$a\left(-x + t\cdot\dfrac{b}{\gcd(a, b)}\right) - b\left(-y + t\cdot\dfrac{a}{\gcd(a, b)}\right)=\gcd(a, b), t\in \mathbb{N}$

對照原本的式子，多出的那幾項會抵消掉，因此等式仍成立。

接下來就是找一個夠大的整數 $t$ 來調整新的 $x, y$ 值就可以了。

---

我們令 $A, B$ 為題目中原本的 $n, m$ (常數)，而 $a, b$ 一開始也為 $n, m$ (變數)。

我們將在一般的輾轉相除法之同時 ($\begin{cases}a\mathrel{:=} b\\b\mathrel{:=} a\bmod b\end{cases}$) 的每一次迭代之下，這兩個等式都必須要成立：

$\begin{cases}
Ax-By = a\quad\text{--- (1)}\\
Ax_1-By_1 = b\quad\text{--- (2)}\\
\end{cases}$

如此一來，最後 $a = \gcd(a, b), b = 0$ 時 $x, y$ 就是我們的答案了。

而在「下一輪迭代時」($x\mathrel{:=} x_1, y\mathrel{:=} y_1$) 時，我們有另外一組等式：

$\begin{cases}
Ax_1-By_1 = b\quad\text{--- (2)}\\
Ax_2-By_2 = a \bmod b = a - b\cdot\left\lfloor\dfrac ab\right\rfloor\quad\text{--- (3)}\\
\end{cases}$

將 $\text{(2)}$ 代入 $\text{(3)}$ 後我們有：

$Ax_2-By_2 = a - (Ax_1+By_1)\cdot\left\lfloor\dfrac ab\right\rfloor\\
\Rightarrow A(x_2-x_1\cdot\left\lfloor\dfrac ab\right\rfloor) - B(y_2 - y_1\cdot\left\lfloor\dfrac ab\right\rfloor) = a\quad\text{--- (4)}$

比較 $\text{(1)}$ 和 $\text{4}$ 後我們可以得出每次迭代的轉換式：

$\begin{cases}
x = x_2-x_1\cdot\left\lfloor\dfrac ab\right\rfloor\\
y = y_2 - y_1\cdot\left\lfloor\dfrac ab\right\rfloor
\end{cases}\\
\Rightarrow
\begin{cases}
x_2 = x-x_1\cdot\left\lfloor\dfrac ab\right\rfloor\\
y_2 = y-y_1\cdot\left\lfloor\dfrac ab\right\rfloor
\end{cases}$

以程式的角度來看，也就是說
$\begin{cases}
x_1 \mathrel{:=}  x-x_1\cdot\left\lfloor\dfrac ab\right\rfloor\\
y_1 \mathrel{:=}  y-y_1\cdot\left\lfloor\dfrac ab\right\rfloor
\end{cases}$

當然別忘了
$\begin{cases}
x \mathrel{:=}  x_1\\
y \mathrel{:=}  y_1
\end{cases}$
。

如此一來，我們就可以確定「過程」絕對是 ok 的了。

---

最後，處理一下 $x, y, x_1, y_1$ 的初始值。

一開始時 $a = A, b = B$，再觀察一下 $\text{(1)}$, $\text{(2)}$，我們可以發現：

$\begin{cases}
A(1)-B(0) = a\\
A(0)-B(-1) = b\\
\end{cases}
\Rightarrow
\begin{cases}
x = 1\\
y = 0\\
x_1 = 0\\
y_1 = -1\\
\end{cases}$

---

最後把答案處理成(最小)正數解的時候，我們想要達成的是：

$\begin{cases}
x + t \cdot \frac{B}{\gcd} \ge 0 \implies t \ge \frac{-x \cdot \gcd}{B}\\
y + t \cdot \frac{A}{\gcd} \ge 0 \implies t \ge \frac{-y \cdot \gcd}{A}
\end{cases}$

因此我們的 $t$ 可以選定為 $\max\left(\dfrac {-x\cdot\gcd}B, \dfrac {-y\cdot\gcd}A\right)$。

在範例的實作過程中，我們是將 $x, y$ 減去 $t$ 倍而不是加上 $t$ 倍，因此選定的 $t = \min\left(\dfrac {x\cdot\gcd}B, \dfrac {y\cdot\gcd}A\right)$。因為 C++ 是向零取整，如果 $x, y< 0$，記得把 $t$ 減去 $1$。。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler [數學] 迭代式擴充歐幾里得演算法
```cpp!
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
    long long n, m, k; cin>>n>>m>>k;

    long long a = n, b = m, x = 1, y = 0, x1 = 0, y1 = -1;
    while (b) {
        tie(x, x1) = make_tuple(x1, x - a / b * x1);
        tie(y, y1) = make_tuple(y1, y - a / b * y1);
        tie(a, b) = make_tuple(b, a % b);
    }
    tie(x, y) = make_tuple(x * k / a, y * k / a);
    tie(n, m) = make_tuple(n / a, m / a);

    long long q = min(x / m, y / n) - (min(x, y) < 0);
    cout << x - q * m << ' ' << y - q * n << '\n';
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c014

對於每週，你的任務就是比較「至今所有的功課量」還有「至今所有寫完的頁數」。由於寫的頁數可能會到 $5\cdot 10^9$，所以請使用 `long long`。

接下來，把這週的完成情況記錄在陣列上，最後看看前三週被感動幾次就好了。

一個比較漂亮的做法是把前三週的完成情況紀錄在一個長度為三的陣列上，每次把目前的週次對 $3$ 取模。由於你會一直重複使用那個陣列，所以記得就算這週沒有被感動也要把那一格覆蓋上 $0$。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler for 迴圈 + 陣列
```cpp!
#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;

    long long tasks[100005], record[100005];

    for (int i=0;i<n;i++) {
        cin >> tasks[i];
    }

    long long progress = 0, homework = 0;
    for (int i=0;i<n;i++) {
        homework += tasks[i];
        for (int j=0;j<5;j++) {
            int a;
            cin>>a;
            progress += a;
        }

        if (progress >= homework) record[i] = 0;
        else record[i] = 1;

        int touched = 0;
        for (int j=i;j>=i-2;j--) {
            if (j >= 0) {
                touched += record[j];
            }
        }
        
        if (touched == 0) {
            cout << "國文老師人美心善怎麼可以不交作業呢" << endl;
        } else if (touched == 1) {
            cout << "國文老師你的話讓我有點感動" << endl;
        } else {
            cout << "國文老師你的話真令人感動" << endl;
        }
    }
}
```
:::
:::spoiler [小技巧] 滾動陣列 + accumulate 函式
```cpp!
#include <bits/stdc++.h>

using namespace std;

constexpr const char* const ver[] = {
    "國文老師人美心善怎麼可以不交作業呢\n",
    "國文老師你的話讓我有點感動\n",
    "國文老師你的話真令人感動\n",
    "國文老師你的話真令人感動\n"
};

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin>>n;
    long long tasks[100005];
    for (int i=0;i<n;i++) {
        cin >> tasks[i];
        if (i) tasks[i] += tasks[i-1];
    }
    long long record[3] = {}, progress = 0;
    for (int i=0;i<n;i++) {
        for (int j=0;j<5;j++) {
            int a; cin>>a; progress += a;
        }
        if (progress >= tasks[i]) record[i % 3] = 0;
        else record[i % 3] = 1;
        cout << ver[accumulate(record, record+3, 0)];
    }
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c015

我們假設我們最後把所有的木棍的長度改為 $l$，並且原先有 $p$ 個木棍長度 $>l$，$q$ 個木棍長度 $<l$。

在這個情況下，我們如果把 $l$ 加上 $1$，則我們的花費會多 $p-q$，反之則會多 $q-p$。

因此，我們想要讓 $p$ 越接近 $q$，也就是說剛好有一半的木棍長度 $>l$，一半木棍長度 $<l$。

也就是說，我們的 $l$ 值就是所有木棍長度的中位數。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler sort 排序 + 陣列
```cpp!
#include <iostream>
#include <algorithm>

using namespace std;

int main() {
	int n;
	cin>>n;

	int p[200005];
	for (int i=0;i<n;i++) {
		cin >> p[i];
	}
	sort(p, p + n);

	long long res = 0;
	for (int i=0;i<n;i++) {
		res += abs(p[i] - p[n/2]);
	}
	
	cout << res << '\n';
}
```
:::
:::spoiler [下學期] vector + accumulate
```cpp!
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);
	int n; cin>>n;
	vector<int> p(n);
	for (auto&x:p) cin>>x;
	sort(p.begin(), p.end());
	cout<< accumulate(p.begin(), p.end(), 0LL, [&p, &n](long long res, long long x){ return res + abs(p[n/2] - x); }) <<'\n';
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c016

整個流程大抵如此(未完賽的部分我當實作細節)：

1. 找出完賽時間最少是誰
2. 對於剩下所有車手，遍歷他們每圈時間，記錄他們被套(倒追)了幾圈。
3. 除了被套幾圈，還要記錄他們總共花多少時間。
4. 依照套圈$\rightarrow$完賽時間的順序比較並排序。
5. 輸出時如果是 `Interval` 模式，記得把比較的那個數值更新。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler bubble sort
```cpp!
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    int inContention = n;
    string drivers[1000];
    double laps[1000][100], finish[1000], leader = 1e9;
    int lapsToGo[1000];
    bool dnf[1000] = {};

    for (int i=0;i<n;i++) {
        cin >> drivers[i];
        double temp = 0;

        for (int j=0;j<m;j++) {
            cin >> laps[i][j];
            temp += laps[i][j];
            if (laps[i][j] == -1) {
                inContention--;
                dnf[i] = true;
                break;
            }
        }

        if (dnf[i]) {
            continue;
        }

        leader = min(leader, temp);
    } 

    for (int i=0;i<n;i++) {
        if (dnf[i]) {
            lapsToGo[i] = m + 1;
            continue;
        }
        double curr = 0;
        for (int j=0;j<m;j++) {
            curr += laps[i][j];
            if (curr >= leader) {
                finish[i] = curr;
                lapsToGo[i] = m - j - 1;
                break;
            }
        }
    }

    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (lapsToGo[i] > lapsToGo[j] or lapsToGo[i] == lapsToGo[j] and finish[i] > finish[j]) {
                swap(finish[i], finish[j]);
                swap(lapsToGo[i], lapsToGo[j]);
                swap(drivers[i], drivers[j]);
            }
        }
    }

    string s;
    cin >> s;

    cout << fixed << setprecision(3);
    int leaderLaps = 0;
    double leaderTime = leader;
    for (int i=0;i<inContention;i++) {
        if (i == 0) {
            cout << drivers[i] << ' ' << finish[i] << endl;
        } else {
            if (leaderLaps == lapsToGo[i]) {
                cout << drivers[i] << " +" << finish[i] - leaderTime << endl;
            } else {
                cout << drivers[i] << " +" << lapsToGo[i] - leaderLaps << " Lap";
                if (lapsToGo[i] - leaderLaps > 1) cout << "s";
                cout << endl;
            }

            if (s == "Interval") {
                leaderTime = finish[i];
                leaderLaps = lapsToGo[i];
            }
        }
    }
}
```
:::
:::spoiler [超綱] vector, struct, 運算子重載, 陣列上二分搜
```cpp!
#include <bits/stdc++.h>

using namespace std;

struct d {
    int lapsToGo;
    double t;
    string name;
};

bool operator < (d& lhs, d& rhs) {
    if (lhs.lapsToGo == rhs.lapsToGo) return lhs.t < rhs.t;
    else return lhs.lapsToGo < rhs.lapsToGo;
}

int main() {
    cin.tie(0)->sync_with_stdio(0);
    
    int n, m; cin >> n >> m;

    unordered_map<string, vector<double>> dt;
    double leader = 1e9;
    for (int i=0;i<n;i++) {
        string tag; cin>>tag;

        vector<double> laps;
        for (int j=0;j<m;j++) {
            double t; cin>>t;
            if (abs(t + 1) < 1e-7) break;
            else {
                laps.push_back(t);
                if (j) laps[j] += laps[j-1];
            }
        }
        
        if (laps.size() == m) {
            leader = min(leader, laps.back());
            dt[tag] = {};
            dt[tag].swap(laps);
        }
    }
    
    vector<d> res;
    for (auto&[tag, laps]:dt) {
        auto it = lower_bound(laps.begin(), laps.end(), leader);
        res.push_back(d{(int)(laps.end() - it) - 1, *it, tag});
    }
    sort(res.begin(), res.end());

    string s; cin>>s; cout << fixed << setprecision(3);

    auto cmp = res.front();
    for (auto&x:res) {
        if (x.lapsToGo == 0 and x.t == leader)
            cout << x.name << " " << x.t << '\n';
        else {
            int gap = x.lapsToGo - cmp.lapsToGo;
            if (gap == 0)
                cout << x.name << " +" << x.t - cmp.t << '\n';
            else
                cout << x.name << " +" << gap << (gap == 1? " Lap\n": " Laps\n");
            if (s == "Interval") swap(x, cmp);
        }
    }
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c017

就寫個 bubble sort 吧！

記得事件名稱要用 `getline()` 讀取。

你可以選擇要在排序時就先把規則寫好或是照月份日期排序後再分兩段輸出。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler bubble sort
```cpp!
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, m, d; cin>>n>>m>>d;

    string title[1000];
    int month[1000], date[1000];

    for (int i=0;i<n;i++) {
        cin >> month[i] >> date[i];
        getline(cin, title[i]);
    }

    for (int i=0;i<n;i++) {
        for (int j=i+1;j<n;j++) {
            if (month[i] > month[j] or month[i] == month[j] and date[i] > date[j]) {
                swap(month[i], month[j]);
                swap(date[i], date[j]);
                swap(title[i], title[j]);
            }
        }
    }

    for (int i=0;i<n;i++) {
        if (month[i] > m or month[i] == m and date[i] >= d) {
            cout << month[i] << ' ' << date[i] << title[i] << endl;
        }
    }
    for (int i=0;i<n;i++) {
        if (month[i] < m or month[i] == m and date[i] < d) {
            cout << month[i] << ' ' << date[i] << title[i] << endl;
        }
    }
}
```
:::
:::spoiler [超綱] sort 匿名函式自訂比較
```cpp!
#include <bits/stdc++.h>

using namespace std;

struct event {
    int month, date;
    string title;
};

int main() {
    int n, m, d; cin>>n>>m>>d;

    vector<event> g(n);
    for (auto&x:g) cin>>x.month>>x.date, cin.get(), getline(cin, x.title);

    sort(g.begin(), g.end(), [&m, &d](event&lhs, event&rhs){
        if ((lhs.month < m or lhs.month == m and lhs.date < d) == (rhs.month < m or rhs.month == m and rhs.date < d))
            return (lhs.month == rhs.month? lhs.date < rhs.date: lhs.month < rhs.month);
        else
            return (lhs.month < m or lhs.month == m and lhs.date < d? false: true);
    });
    for (auto&x:g) cout << x.month << ' ' << x.date << ' ' << x.title << '\n';
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c019

題序讀好就可以了！

如果真的讀不懂也沒關係，可以嘗試直接寫程式碼，你會發現題目的敘述幾乎可以直接翻譯成 code。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler 陣列複製
```cpp!
#include <iostream>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    int songs[100005], a[100005], new_songs[100005];
    for (int i = 1;i<=n;i++) {
        cin >> songs[i];
    }
    
    while (q--) {
        int f;
        cin>>f;
        
        for (int i=1;i<=n;i++) {
            cin >> a[i];
        }
        
        for (int i=1;i<=n;i++) {
            if (f == 1) {
                new_songs[i] = songs[a[i]];
            } else {
                new_songs[a[i]] = songs[i];
            }
        }

        
        for (int i=1;i<=n;i++) {
            songs[i] = new_songs[i];
        }
    }
    
    for (int i=1;i<=n;i++) {
        cout << songs[i] << ' ';
    }
}
```
:::
:::spoiler [下學期] 指標交換
```cpp!
#include <iostream>

using namespace std;

int main() {
    int n, q;
    cin >> n >> q;
    
    int *before = new int[100005], *after = new int[100005];

    for (int i = 1;i<=n;i++) {
        cin >> before[i];
    }

    while (q--) {
        int f;
        cin>>f;
        
        for (int i=1;i<=n;i++) {
            int a; cin >> a;
            if (f == 1) {
                after[i] = before[a];
            } else {
                after[a] = before[i];
            }
        }
        swap(before, after);
    }
    
    for (int i=1;i<=n;i++) {
        cout << before[i] << ' ';
    }
}
```
:::
:::spoiler [下學期] vector + swap
```cpp!
#include <bits/stdc++.h>

using namespace std;

int main() {    
    int n, q; cin>>n>>q;
    vector<int> songs(n); for (auto&x:songs) cin>>x;
    while (q--) {
        int op; vector<int> new_songs(n), a(n);
        cin >> op; for (auto&x:a) cin>>x;
        for (int i=0;i<n;i++) {
            if (op == 1) new_songs[i] = songs[a[i]-1];
            else new_songs[a[i]-1] = songs[i];
        }
        songs.swap(new_songs);
    }
    for (auto&x:songs) cout << x << " \n"[&x == &songs.back()];
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c020

你有兩種選擇：

1. 讀到 `1` 時判斷下一個是不是 `0`，如果是的話那就代表指令在這個 `1` 結束。
2. 讀到 `0` 時判斷上一個是不是 `1`，如果是的話那就代表指令已經完成。

選擇 1. 的話最後一個時間單位要多做動作，如果選擇 2. 的實作方式的話那就要先讀入第一個指令再開始迴圈，然後最後多加上一個 `0`。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler 陣列 + 運算子
```cpp!
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q; 
    cin >> n >> q;

    int songs[100005];
    for (int i = 0; i < n; ++i) {
        cin >> songs[i];
    }

    int last_op, curr_id = 0, elapsed = 1, playing = 1; 
    cin >> last_op;

    int op[100005];
    for (int i = 0; i < q - 1; ++i) {
        cin >> op[i];
    }
    op[q - 1] = 0;

    for (int i = 0; i < q; ++i) {
        int x = op[i];
        
        if (playing && ++elapsed > songs[curr_id]) {
            elapsed = 1;
            curr_id = (curr_id + 1) % n;
        }

        if (x) {
            last_op++;
        } else {
            if (last_op == 1) {
                playing ^= 1;
            } else if (last_op == 2) {
                playing = 1; 
                elapsed = 1; 
                curr_id = (curr_id + 1) % n;
            } else if (last_op == 3) {
                playing = 1; 
                elapsed = 1; 
                curr_id = (curr_id + n - 1) % n;
            }
            last_op = 0;
        }
    }

    cout << curr_id + 1 << '\n';
}
```
:::
:::spoiler [下學期] vector
```cpp!
#include <bits/stdc++.h>

using namespace std;

int main() {
    int n, q; cin>>n>>q;
    vector<int> songs(n);
    for (auto&x:songs) cin>>x;

    int last_op, curr_id = 0, elapsed = 1, playing = 1; cin>>last_op;

    vector<int> op(q - 1); 
    for (auto&x:op) cin>>x; op.push_back(0);

    for (auto&x:op) {
        if (playing and ++elapsed > songs[curr_id])
            elapsed = 1, curr_id = (curr_id + 1) % n;

        if (x) last_op++;
        else {
            if (last_op == 1) playing ^= 1;
            else if (last_op == 2) playing = 1, elapsed = 1, curr_id = (curr_id + 1) % n;
            else if (last_op == 3) playing = 1, elapsed = 1, curr_id = (curr_id + n - 1) % n;
            last_op = 0;
        }
    }

    cout << curr_id + 1 << '\n';
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c021

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler while 迴圈
對不起我懶得寫ww
:::

:::spoiler [下學期] 遞迴
```cpp!
#include <bits/stdc++.h>

using namespace std;

vector<string> g;

void solve(int l, int r, bool skip = false) {
    int ptr = l, L = -1;
    while (ptr != r) {
        if (g[ptr] == "||:") { L = ptr++; continue; }

        if (g[ptr] == ":||") {
            if (skip) break;
            solve(L + 1, ptr++, true); continue;
        }

        if (g[ptr] == "1.") {
            ptr++;
            if (skip) break;
            continue;
        }

        if (g[ptr] == "]" or g[ptr] == "2.") { ptr++; continue; }

        cout << g[ptr++] << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin>>n;
    g.resize(n); for (auto&x:g) cin>>x;
    solve(0, n);
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c022

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler while 迴圈
對不起我又懶得寫了ww
:::

:::spoiler [下學期] 遞迴
```cpp!
#include <bits/stdc++.h>

using namespace std;

vector<string> g;

constexpr array<string_view, 11> keywords = {
    "DSAlCoda", "DCAlCoda", "DSAlFine", "DCAlFine", "Segno", "Coda", "ToCoda", "Fine", "1.", "2.", "]"
};

void solve(int l, int r, bool skip = false) {
    int ptr = l, L = -1;
    while (ptr < r) {
        if (g[ptr] == "||:") { L = ptr++; continue; }

        if (skip and (g[ptr] == "1." or g[ptr] == ":||")) {
            while (g[ptr] != ":||") ptr++;
            solve(ptr + 1, r, skip); break;
        }
        
        if (g[ptr] == ":||") { solve(L + 1, ptr++, true); continue; }
        
        if (find(keywords.begin(), keywords.end(), g[ptr]) != keywords.end()) { ptr++; continue; }

        cout << g[ptr++] << ' ';
    }
}

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin>>n;
    
    int SC = -1, SF = -1, CC = -1, CF = -1, S = -1, C = -1, TC = -1, F = -1;

    g.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> g[i];
        if (g[i] == "DSAlCoda") SC = i;
        if (g[i] == "DCAlCoda") CC = i;
        if (g[i] == "DSAlFine") SF = i;
        if (g[i] == "DCAlFine") CF = i;
        if (g[i] == "Segno") S = i;
        if (g[i] == "Coda") C = i;
        if (g[i] == "ToCoda") TC = i;
        if (g[i] == "Fine") F = i;
    }

    if (SC != -1) {
        solve(0, SC);
        solve(S + 1, TC, true);
        solve(C + 1, n, true);
    } else if (CC != -1) {
        solve(0, CC);
        solve(0, TC, true);
        solve(C + 1, n, true);
    } else if (SF != -1) {
        solve(0, SF);
        solve(S + 1, F, true);
    } else if (CF != -1) {
        solve(0, CF);
        solve(0, F, true);
    } else {
        solve(0, n);
    }
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c023

只要記錄兩個東西就好了：目前記錄到的最長坡的長度，以及目前的坡的長度。

只要前一項比這一項還要大，就可以增加目前的坡的長度，不然就歸零。

至於要怎麼紀錄，你可以額外開一個變數紀錄，初始值設無限大(`1e9+`)，或者是把索引值減 $1$，記得留意負數取模。

由於外環道是環狀的，所以最差的情況下你需要遍歷整個陣列兩次。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler 陣列 + 取模
```cpp!
#include <iostream>

using namespace std;

int main() {
    int n; cin>>n;
    
    int a[100005];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }

    int curr = 0, res = 1;
    for (int i=1;i<=2*n;i++) {
        if (a[i%n] > a[(i-1)%n]) curr++;
        else {
            res = max(res, curr);
            curr = 1;
        }
    }
    cout << res << endl;
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c024

首先，你需要把讀入的資料轉換為一塊一塊的，以連續幾個「有/沒有人」來記錄。

第一個答案很簡單，就是把每一個有人的塊的大小$\div2$加總。

第二、三個答案，需要一些觀察，在廁所中間的塊都是 $\left\lfloor\frac{n-1}2\right\rfloor$ 和 $\left\lfloor\frac n3\right\rfloor$，在最左/右邊的塊，公式需要稍作校正。

最後一個答案的部分，我們發現如果要移除違反公約的人，連續的偶數個人可以多為左右兩邊的其中一段增加 $1$ 一格的空間。

我們用以下策略來算出答案，不難證明這一定是最好的方式。

1. 對於多出的一個空格，如果憑它一己之力就可以使廁所多塞一人，那一定是好的。
2. 對於多的一格，如果單憑前面的庫存見能夠使上一個無人段增加一個使用機會，那就用掉庫存。
3. 連著前面的庫存(也可能是0)，如果這一個新空格分給前一個無人段可以使人數增加，那就分給前一塊。前面的庫存不用就必須得捨棄，能讓使用機會從不能增加到能增加，花掉這個新空格是有意義的，絕對是件好事。
4. 如果不能使前一塊的人數增加，那就先存起來。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler 陣列 + 小實作
```cpp!
#include <iostream>

using namespace std;

int main() {
    int n;
    cin >> n;
    
    int types[n + 5];
    int streaks[n + 5];
    int m = 0;

    int res1 = 0, res2 = 0, res3 = 0, res4 = 0;

    for (int i = 0, type = -1, streak = 0; i <= n; i++) {
        int k = type ^ 1;
        if (i < n) cin >> k;

        if (k != type) {
            if (streak) {
                types[m] = type;
                streaks[m] = streak;
                m++;
                if (!k) res1 += streak / 2;
            }
            streak = 0;
        }
        type = k; streak++;
    }

    int quota = (types[0] and !(streaks[0] % 2));
    for (int i = 0; i < m; i++) {
        int ends = (i == 0) + (i == m - 1);

        if (!types[i]) {
            res2 += (streaks[i] - 1 + ends) / 2;
            res3 += (streaks[i] + ends) / 3;
        } else if (i != 0) {
            bool oneleft = (i - 1 == 0 and streaks[i - 1] % 2 == 1) or
                (i - 1 != 0 and streaks[i - 1] % 2 == 0);

            if (quota == 1 and oneleft) {
                res4++; quota = streaks[i] % 2 == 0;
            } else {
                quota += streaks[i] % 2 == 0;
                if (quota == 2 or (quota == 1 and oneleft)) {
                    res4++; quota = 0;
                } else {
                    quota = streaks[i] % 2 == 0;
                }
            }
        }
    }
    if (types[m - 1] == 0 and streaks[m - 1] % 2 == 1 and quota == 1)
        res4++;

    cout << res1 << ' ' << res2 << ' ' << res3 << ' ' << res2 + res4 << '\n';
}
```
:::
:::spoiler [下學期] vector, pair, 記憶體位置
```cpp!
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int n; cin>>n;
    vector<pair<int, int>> a;

    int res1 = 0, res2 = 0, res3 = 0, res4 = 0;

    for (int i=0, type=-1, streak=0; i<=n; i++) {
        int k = type ^ 1;
        if (i < n) cin>>k;

        if (k != type) {
            if (streak) {
                a.push_back({type, streak});
                if (!k) res1 += streak / 2;
            }
            streak = 0;
        }
        type = k; streak++;
    }

    int quota = (a.front().first and !(a.front().second % 2));
    for (auto&x:a) {
        int ends = (&x == &a.front()) + (&x == &a.back());

        if (!x.first) {
            res2 += (x.second - 1 + ends) / 2;
            res3 += (x.second + ends) / 3;
        } else if (&x != &a.front()) {
            bool oneleft = (&x - 1 == &a.front() and (&x - 1)->second % 2 == 1) or
                (&x - 1 != &a.front() and (&x - 1)->second % 2 == 0);

            if (quota == 1 and oneleft) {
                res4++; quota = x.second % 2 == 0;
            } else {
                quota += x.second % 2 == 0;
                if (quota == 2 or quota == 1 and oneleft) {
                    res4++; quota = 0;
                } else {
                    quota = x.second % 2 == 0;
                }
            }
        }
    }
    if (a.back().first == 0 and a.back().second % 2 == 1 and quota == 1)
        res4++;

    cout << res1 << ' ' << res2 << ' ' << res3 << ' ' << res2+res4 << '\n';
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c026

這題最好做的方式其實是一維陣列而不是二維。如果你可以照著輪轉的順序(順時針)存下隊員，以「輸入資料時比較麻煩」換取「輪轉非常容易」。

如果左隊用 `l[]` 紀錄，右隊用 `r[]` 來記錄，你可以依照這個順序來記錄：

$\begin{array}{|c|c|c|c|}\hline
l[2] & l[3] & r[2] & r[3] \\\hline
l[1] & l[4] & r[1] & r[4] \\\hline
l[0] & l[5] & r[0] & r[5] \\\hline
\end{array}$

輸出時以這個順序輸出：

$\begin{array}{|c|c|c|}\hline
l[0] & l[1] & l[2] \\\hline
l[5] & l[4] & l[3] \\\hline
r[0] & r[1] & r[2] \\\hline
r[5] & r[4] & r[3] \\\hline
\end{array}$

如果有輪轉，把索引值減去輪轉次數後 $\bmod 6$ 就可以了，輪轉真的就這麼容易。當然，留意負數取模。

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler 陣列 + 取模
```cpp!
#include <iostream>

using namespace std;

int main() {
    int q;
    cin>>q;

    int l[6], r[6];
    for (int i=2;i>=0;i--) {
        cin >> l[i] >> l[5-i] >> r[i] >> r[5-i];
    }

    int last = -1, down = 0, up = 0;
    while (q--) {
        int serve;
        cin >> serve;

        if (serve != last and last != -1) {
            if (serve == 0) {
                up++;
            } else {
                down++;
            }
        }
        last = serve;
    }

    for (int i=0;i<3;i++) {
        cout << l[(6 - up % 6 + i) % 6] << ' ';
    }
    cout << endl;

    for (int i=5;i>=3;i--) {
        cout << l[(6 - up % 6 + i) % 6] << ' ';
    }
    cout << endl;

    for (int i=0;i<3;i++) {
        cout << r[(6 - down % 6 + i) % 6] << ' ';
    }
    cout << endl;

    for (int i=5;i>=3;i--) {
        cout << r[(6 - down % 6 + i) % 6] << ' ';
    }
    cout << endl;
}
```
:::
:::spoiler [下學期] vector
```cpp!
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int q; cin>>q;

    vector<int> l(6), r(6);
    for (int i=2;i>=0;i--) cin >> l[i] >> l[5-i] >> r[i] >> r[5-i];

    int up = 0, down = 0, last, serve = -1;
    while (last = serve, q--) {
        if (cin >> serve, serve != last and last != -1) serve? down++: up++;
    }
    
    for (int i=0;i<3;i++) cout << l[(6 - up % 6 + i) % 6] << " \n"[i == 2];
    for (int i=5;i>=3;i--) cout << l[(6 - up % 6 + i) % 6] << " \n"[i == 3];
    for (int i=0;i<3;i++) cout << r[(6 - down % 6 + i) % 6] << " \n"[i == 2];
    for (int i=5;i>=3;i--) cout << r[(6 - down % 6 + i) % 6] << " \n"[i == 3];
}
```
:::
:::spoiler 二維陣列
```cpp!
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int q, last, serve = -1; cin>>q;

    vector<vector<int>> teams(2, vector<int>(6));
    for (int i=2;i>=0;i--)
        for (int j=0;j<=1;j++)
            cin >> teams[j][i] >> teams[j][5-i];

    vector<int> rotate(2);
    while (last = serve, q--)
        if (cin>>serve, serve != last and last != -1)
            rotate[serve]++;

    for (int j=0;j<=1;j++) {
        for (int i=0;i<3;i++)
            cout << teams[j][(6 - rotate[j] % 6 + i) % 6] << " \n"[i == 2];
        for (int i=5;i>=3;i--)
            cout << teams[j][(6 - rotate[j] % 6 + i) % 6] << " \n"[i == 3];
    }
}
```
:::
:::spoiler [超綱] deque
```cpp!
#include <bits/stdc++.h>

using namespace std;

int main() {
    cin.tie(0)->sync_with_stdio(0);

    int q; cin>>q;

    deque<int> l(6), r(6);
    for (int i=2;i>=0;i--) cin >> l[i] >> l[5-i] >> r[i] >> r[5-i];

    int last, serve = -1;
    while (last = serve, q--) {
        if (cin>>serve, serve != last and last != -1) {
            if (serve) {
                l.push_front(l.back());
                l.pop_back();
            } else {
                r.push_front(r.back());
                r.pop_back();
            }
        }
    }
    
    for (int i=0;i<3;i++) cout << l[i] << " \n"[i == 2];
    for (int i=5;i>=3;i--) cout << l[i] << " \n"[i == 3];
    for (int i=0;i<3;i++) cout << r[i] << " \n"[i == 2];
    for (int i=5;i>=3;i--) cout << r[i] << " \n"[i == 3];
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c028

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler 陣列, 無條件進位
```cpp!
#include <iostream>

using namespace std;

int main() {
    int n;
    cin>>n;
    int a[100005], b[100005];
    for (int i=0;i<n;i++) {
        cin >> a[i];
    }
    for (int i=0;i<n;i++) {
        cin >> b[i];
    }
    int me = 0, bus = 0;

    for (int i=0;i<n;i++) {
        int t, p, q;
        cin>>t>>p>>q;

        me += a[i];
        bus += b[i];

        if (p < q and !(p <= bus % t and bus % t < q) or
            p > q and (q <= bus % t and bus % t < p))
            bus = (bus - p - 1 + t) / t * t + p;
        if (bus > me) {
            cout << "YES" << endl;
            return 0;
        }
        if (p < q and !(p <= me % t and me % t < q) or
            p > q and (q <= me % t and me % t < p))
            me = (me - p - 1 + t) / t * t + p;
    }
    cout << "NO" << endl;
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c031

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler 陣列
```cpp!
#include <iostream>

using namespace std;

int votes[100005];

int main() {
    long long n, m, res, v = 0;
    cin>>n>>m;
    for (int i=0;i<m;i++) {
        int a;
        cin>>a;
        if (++votes[a] > v) {
            v = votes[a], res = a;
        }
    }
    cout << res << '\n';
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c032

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler string 字串
```cpp!
#include <bits/stdc++.h>

using namespace std;

int main() {
    string s;
    cin>>s;

    int curr = 0, res = 1;
    
    for (int i=1;i<s.size();i++) {
        if (s[i] != s[i-1]) {
            curr = 0;
        }
        res = max(res, ++curr);
    }
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c033

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler string + 陣列
```cpp!
#include <iostream>

using namespace std;

int main() {
    int a[26] = {};
    string s;
    cin>>s;
    
    for (int i=0;i<s.size();i++) {
        a[s[i]-'A']++;
    }
    
    bool possible = true;
    char middle;
    for (int i=0;i<26;i++) {
        if (a[i] % 2 == 1) {
            if (possible) {
                possible = false;
                middle = 'A' + i;
            } else {
                cout << "NO SOLUTION" << endl;
                return 0;
            }
        }
    }
    for (int i=0;i<26;i++) {
        char c = 'A' + i;
        for (int j=0;j<a[i]/2;j++) {
            cout << c;
        }
    }
    if (!possible) {
        cout << middle;
    }
    for (int i=25;i>=0;i--) {
        char c = 'A' + i;
        for (int j=0;j<a[i]/2;j++) {
            cout << c;
        }
    }
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c034

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler sort 排序
```cpp!
#include <iostream>
#include <algorithm>
 
using namespace std;

int main() {
    int n, k, base;
    cin>>n>>k;
    
    int h[100005];
    for (int i=0;i<n;i++) {
        cin >> h[i];
    }
    base = h[k-1];
    
    sort(h, h + 5);
    
    int i = 0;
    while (h[i] < base) {
        i++;
    }
    
    for (; i < n; i++) {
        if (h[i] - base > h[i-1]) {
        	cout << "NO" << endl;
        	return 0;
		}
    }
    cout<<"YES\n";
}
```
:::
:::spoiler [超綱] set
```cpp!
#include <bits/stdc++.h>
 
using namespace std;

int main() {
    set<int> s;
    int n, k, base; cin>>n>>k;
    
    vector<int> h(n);
    for (auto&x:h) cin>>x;
    base = h[k-1];
    
    for (int i=0;i<n;i++)
        if (h[i]>=base) s.insert(h[i]);
    
    for (auto it = next(s.begin()); it != s.end(); it++) {
        if (*it - base > *prev(it)) {
        	cout << "NO" << endl;
        	return 0;
		}
    }
    cout<<"YES\n";
}
```
:::

  </div>
</div>

<div class="two-column-grid">
  <div class="column">

## c035

  </div>
  <div class="column">

## C++ 程式碼

:::spoiler string + 取模 + 型態轉換
```cpp!
#include <iostream>
 
using namespace std;

int main() {    
    int n, k;
    cin>>n>>k;

    while (n--) {
        string s;
        cin>>s;
        
        for (int i=0;i<s.size();i++) {
            if (isupper(s[i])) cout << (char)((s[i] - 'A' + 26 - k) % 26 + 'A');
            else if (islower(s[i])) cout << (char)((s[i] - 'a' + 26 - k) % 26 + 'a');
            else cout << s[i];
        }
        cout << ' ';
    }
}
```
:::

  </div>
</div>