#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class GameEntry {
public:
    GameEntry(const string& n = " ", int s = 0);
    string getName() const;
    int getScore() const;

private:
    string name;
    int score;
};

class HighScore
{
public:
    HighScore(int maxEntry = 10);
    ~HighScore();
    void printEntries();
    void add(const GameEntry& e);
    GameEntry remove(int i)
        throw(out_of_range);                                // out_of_range is the exception in C++
    void insertionSort(GameEntry*, int);

private:
    int maxEntries;
    int numEntries;
    GameEntry* entries;
};

int main()
{
    HighScore newHighScore(10);
    GameEntry newGameEntry1("Guest1", 110);
    GameEntry newGameEntry2("Guest2", 101);
    GameEntry newGameEntry3("Guest3", 200);
    GameEntry newGameEntry4("Guest4", 999);
    GameEntry newGameEntry5("Guest5", 500);
    GameEntry newGameEntry6("Guest6", 178);
    GameEntry newGameEntry7("Guest7", 145);
    GameEntry newGameEntry8("Guest8", 155);
    GameEntry newGameEntry9("Guest9", 115);
    GameEntry newGameEntry10("Guest10", 100);
    GameEntry newGameEntry11("Guest11", 510);               // Tests for a new entry larger some others while array is full
    GameEntry newGameEntry12("Guest12", 10);                // Tests for a new entry lower than others while array is full

    newHighScore.add(newGameEntry1);
    newHighScore.add(newGameEntry2);
    newHighScore.add(newGameEntry3);
    newHighScore.add(newGameEntry4);
    newHighScore.add(newGameEntry5);
    newHighScore.add(newGameEntry6);
    newHighScore.add(newGameEntry7);
    newHighScore.add(newGameEntry8);
    newHighScore.add(newGameEntry9);
    newHighScore.add(newGameEntry10);
    newHighScore.add(newGameEntry11);
    newHighScore.add(newGameEntry12);

    newHighScore.printEntries();

    cout << "\nTest with 2nd largest entry removed and new entry inserted at the beginning:" << endl;

    newHighScore.remove(8);                                 // removes 9th item in entries which is the second largest
    GameEntry newGameEntry13("Guest13", 1001);
    newHighScore.add(newGameEntry13);
    newHighScore.printEntries();

    cout << "\nTest with new entry in the middle:" << endl; // Test with new entry in the middle
    newHighScore.remove(9);
    GameEntry newGameEntry14("Guest14", 400);
    newHighScore.add(newGameEntry14);
    newHighScore.printEntries();
    
    cout << "\nTest with new entry in the end:" << endl;    // Test with new entry in the end
    newHighScore.remove(0);
    GameEntry newGameEntry15("Guest15", 40);
    newHighScore.add(newGameEntry15);
    newHighScore.printEntries();

    return 0;
}

GameEntry::GameEntry(const string& n, int s)            // Stores name and score of entry into an object
    : name(n), score(s) { }

string GameEntry::getName() const { return name; }      // returns name
int GameEntry::getScore() const { return score; }       // returns score

HighScore::HighScore(int maxEnt) {                      // stores max entry
    maxEntries = maxEnt;
    entries = new GameEntry[maxEntries];
    numEntries = 0;
}

HighScore::~HighScore() {                               // deletes entries object
    delete[] entries;
}

void HighScore::printEntries() {                        // prints entries sorted in descending order
    insertionSort(entries, numEntries);
    for (int i = numEntries - 1; i >= 0; i--) {
        cout << entries[i].getName() << ": ";
        cout << entries[i].getScore() << endl;
    }
}

void HighScore::add(const GameEntry& e) {               // adds new entry if it is larger than other entries or if there is enough slots
    int newScore = e.getScore();
    if (numEntries == maxEntries) {
        if (newScore <= entries[maxEntries - 1].getScore())
            return;
    }
    else numEntries++;

    int i = numEntries - 2;
    while (i >= 0 && newScore > entries[i].getScore()) {
        entries[i + 1] = entries[i];
        i--;
    }
    entries[i + 1] = e;
}

GameEntry HighScore::remove(int i) throw(out_of_range) {    // removes entry
    if ((i < 0) || (i >= numEntries))
        throw out_of_range("Invalid index");
    GameEntry e = entries[i];
    for (int j = i + 1; j < numEntries; j++)
        entries[j - 1] = entries[j];
    numEntries--;
    return e;

}

void HighScore::insertionSort(GameEntry* A, int n) {    // sorts entries in descending order
    for (int i = 1; i < n; i++) {
        GameEntry cur = A[i];
        int j = i - 1;
        while ((j >= 0) && (A[j].getScore() > cur.getScore())) {
            A[j + 1] = A[j];
            j--;
        }
        A[j + 1] = cur;
    }

}
