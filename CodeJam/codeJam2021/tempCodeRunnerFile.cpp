for (int i = 0; i < N; i++)
  {
    // j - i + 1
    int min_idx;
    if (C > N - i)
      min_idx = N - i - 1, C -= i + N;
    else
      min_idx = C;

    stack<int> C;
    for (int j = i; j <= min_idx; j++)
      C.push(VI[j]);
    int j = 0;
    while (!C.empty())
      VI[i + j] = C.top(), C.pop(), j++;
  }