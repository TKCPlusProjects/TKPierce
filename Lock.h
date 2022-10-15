#pragma once

class Lock
{
private:
    int v;
    static int sv;

    void f(int x, int y) { v = x + y; }
    static void sf(int x, int y) { sv = x + y; }
};
