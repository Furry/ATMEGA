template <typename T>
T pow(T x, T y) {
    T result = 1;
    for (int i = 0; i < y; i++) {
        result *= x;
    }
    return result;
}