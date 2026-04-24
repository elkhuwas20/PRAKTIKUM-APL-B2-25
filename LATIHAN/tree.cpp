#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Item {
int id, weight, value;
double ratio;
};
int knapsackRecursive(int capacity, const vector<Item>& items, int n)
{
if (n == 0 || capacity == 0) return 0;
if (items[n - 1].weight > capacity) {
return knapsackRecursive(capacity, items, n - 1);
}
int take = items[n - 1].value + knapsackRecursive(capacity -
items[n - 1].weight, items, n - 1);
int skip = knapsackRecursive(capacity, items, n - 1);
return max(take, skip);
}
void backtrackSelected(int capacity, const vector<Item>& items, int
n, vector<int>& selected) {
if (n == 0 || capacity == 0) return;
if (items[n - 1].weight > capacity) {
backtrackSelected(capacity, items, n - 1, selected);
return;
}
int takeValue = items[n - 1].value + knapsackRecursive(capacity -
items[n - 1].weight, items, n - 1);
int skipValue = knapsackRecursive(capacity, items, n - 1);
if (takeValue >= skipValue) {
selected.push_back(items[n - 1].id);
backtrackSelected(capacity - items[n - 1].weight, items, n -

1, selected);
} else {
backtrackSelected(capacity, items, n - 1, selected);
}
}
int knapsackGreedy(int capacity, vector<Item> items, vector<int>&
selected) {
sort(items.begin(), items.end(), [](const Item& a, const Item& b)
{

return a.ratio > b.ratio;
});
int totalValue = 0, currentWeight = 0;
for (const auto& item : items) {
if (currentWeight + item.weight <= capacity) {
currentWeight += item.weight;
totalValue += item.value;
selected.push_back(item.id);
}
}
return totalValue;
}
void printResult(const string& method, int totalValue, const
vector<int>& selected) {
cout << "\n[" << method << "]" << endl;
cout << "Total Nilai : " << totalValue << endl;
cout << "Item dipilih: ";
if (selected.empty()) cout << "-";
else {
for (int id : selected) cout << "Item-" << id << " ";
}
cout << endl;
}
int main() {
vector<Item> items = {
{1, 10, 60, 6.0},
{2, 20, 100, 5.0},
{3, 30, 120, 4.0}
};
int capacity = 50;
cout << " = 0/1 KNAPSACK PROBLEM =" << endl;
cout << "Kapasitas Tas: " << capacity << " kg\n" << endl;
// - Greedy -
vector<int> selectedGreedy;
int resGreedy = knapsackGreedy(capacity, items, selectedGreedy);
printResult("GREEDY (Rasio Tertinggi)", resGreedy,
selectedGreedy);
// - Recursive Optimal -
int resRecursive = knapsackRecursive(capacity, items,
items.size());
vector<int> selectedRecursive;
backtrackSelected(capacity, items, items.size(),
selectedRecursive);
printResult("REKURSIF (OPTIMAL)", resRecursive,
selectedRecursive);
// - Kesimpulan -
cout << "\n = KESIMPULAN =" << endl;
if (resRecursive > resGreedy) {
cout << "Greedy GAGAL menemukan solusi optimal!" << endl;
cout << " Optimal = " << resRecursive << ", Greedy = " <<
resGreedy << endl;
cout << " Selisih : " << (resRecursive - resGreedy) << " poin nilai" << endl;
} else {
cout << "Greedy berhasil menemukan solusi optimal!" << endl;
}
return 0;
}