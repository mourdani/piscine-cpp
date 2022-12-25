#ifndef TEMPLATE_TPP
#define TEMPLATE_TPP

template <typename T>
T swap(T &a, T &b) {
    T temp = a;
    a = b;
    b = temp;
  return (temp);
}

template <typename T>
T max(T a, T b) {
  return (a > b ? a : b);
}

template <typename T>
T min(T a, T b) {
  return (a > b ? b : a);
}

#endif

