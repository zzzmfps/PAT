#include <bits/stdc++.h>

int main(void) {
    size_t a1, a2, n;
    std::cin >> a1 >> a2 >> n;
    if (1 == n) {
        std::cout << a1;
        return 0;
    }

    size_t *arr = new size_t[n]{a1, a2};
    size_t i = 0, j = 1, k = 2;
    while (k < n) {
        size_t _next = arr[i++] * arr[j++];
        if (_next < 10) {
            arr[k++] = _next;
        } else {
            arr[k++] = _next / 10;
            if (k == n) break;
            arr[k++] = _next % 10;
        }
    }
    for (size_t l = 0; l < n; ++l) std::cout << (l ? " " : "") << arr[l];

    delete[] arr;
    return 0;
}
