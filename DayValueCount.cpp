#include <bits/stdc++.h>
using namespace std;

map<string, int> solution(map<string, int> date)
{

  map<string, int> count;
  count.insert({"sun", NULL});
  count.insert({"mon", NULL});
  count.insert({"tue", NULL});
  count.insert({"wed", NULL});
  count.insert({"thu", NULL});
  count.insert({"fri", NULL});
  count.insert({"sat", NULL});

  string w;
  int v, k, m, d, c, F;

  for (auto itr = date.begin(); itr != date.end(); ++itr)
  {
    w = itr->first;
    v = itr->second;

    k = stoi(w.substr(8, 2));
    m = stoi(w.substr(5, 2));
    d = stoi(w.substr(2, 2));
    c = stoi(w.substr(0, 2));

    if (m == 1 || 2)
    {
      m = m + 10;
      if (d == 0)
      {
        d = 99;
        c = c - 1;
      }
      else
      {
        d = d - 1;
      }
    }

    F = k + floor((13 * m - 1) / 5) + d + floor(d / 4) + floor(c / 4) - 2 * c;
    if (F < 0)
    {
      if (F % 7 < 0)
      {
        F = (F % 7) + 7;
      }
      else
      {
        F = F % 7;
      }
    }
    else
    {
      F = F % 7;
    }

    if (F == 0)
    {
      auto itr0 = count.find("sun");
      itr0->second += v;
    }

    else if (F == 1)
    {
      auto itr1 = count.find("mon");
      itr1->second += v;
    }

    else if (F == 2)
    {
      auto itr2 = count.find("tue");
      itr2->second += v;
    }

    else if (F == 3)
    {
      auto itr3 = count.find("wed");
      itr3->second += v;
    }

    else if (F == 4)
    {
      auto itr4 = count.find("thu");
      itr4->second += v;
    }

    else if (F == 5)
    {
      auto itr5 = count.find("fri");
      itr5->second += v;
    }

    else if (F == 6)
    {
      auto itr6 = count.find("sat");
      itr6->second += v;
    }

    else
    {
      cout << "day not found \n";
    }
  }
  return count;
};

int main(int argc, char const *argv[])
{
  ios_base::sync_with_stdio(false);
  cin.tie(nullptr);
  cout.tie(nullptr);

  map<string, int> date;

  int l, v;
  string d;

  cout << "Enter number of elements in dictionary and the elements" << endl;

  cin >> l;

  int i = 0;

  for (i = 1; i <= l; i++)
  {
    cin >> d >> v;
    date.insert({d, v});
  }

  cout << '\n';

  map<string, int> count = solution(date);
  for (auto itr = count.begin(); itr != count.end(); ++itr)
  {
    cout << itr->first << "\t" << itr->second << "\n";
  }

  return 0;
}
