#include <iostream>
#include <random>
#include <chrono>
#include "sfl.cpp"
#include <bits/stdc++.h>

int rand_uns(int min, int max)
{
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count();
    static std::default_random_engine e(seed);
    std::uniform_int_distribution<int> d(min, max);
    return d(e);
}

const int N = 100000;

const int M = 1000;
std::vector<subforwardlist*> vectors(M);
std::vector<int> new_elems(M);

unsigned int get_time()
{
    auto start = std::chrono::high_resolution_clock::now();
    
    for (int i = 0; i < M; i++)
    {
        push_forward(vectors[i], new_elems[i]);
    }

    auto end = std::chrono::high_resolution_clock::now();
    
    return (end - start).count();
}

int main()
{
    for (int i = 0; i < M; i++)
    {
        vectors[i] = new subforwardlist;
        init(vectors[i]);
    }

    for (int n = 0; n < N; n++)
    {
        for (int i = 0; i < M; i++)
        {
            new_elems[i] = rand_uns(0, 1000);
            //push_forward(vectors[i], rand_uns(0, 1000));
        }
        std::cout << n << '\t' << get_time() << '\n';
    }

    return 0;
}
