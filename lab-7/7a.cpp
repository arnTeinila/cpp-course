#include <numeric>
#include <iterator>
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>

using namespace std;

class RandomGenerator {
    public:
	RandomGenerator(int lowInit = 1, int highInit = 1) : low(lowInit), high(highInit), numbers() {srand(time(NULL));}
	int operator()();
    private:
	int low;
	int high;
	vector<int> numbers;
};

class printFunc {
    public:
	void operator()(int a){
	    ++index;
	    cout << "#" << index << ": " << a << endl;
	}
    private:
	int index = 0;
} obj;

void print(vector<int> input);

int main(void) {
    vector<int> lotto(7);
    vector<int> vikingLotto(6);
    vector<int> jackpot(5);
    
    vector<int> d(0);
    vector<int> e(0);

    RandomGenerator lottoGen(1,40);
    generate(lotto.begin(), lotto.end(), lottoGen);
    sort(lotto.begin(), lotto.end());

    RandomGenerator vikingGen(1,48);
    generate(vikingLotto.begin(), vikingLotto.end(), vikingGen);
    sort(vikingLotto.begin(), vikingLotto.end());

    RandomGenerator jackpotGen(1,50);
    generate(jackpot.begin(), jackpot.end(), jackpotGen);
    sort(jackpot.begin(), jackpot.end());

    cout << "Lotto: " << endl;
    print(lotto);
    
    cout << "Viking Lotto: " << endl;
    print(vikingLotto);
    
    cout << "Eurojackpot: " << endl;
    print(jackpot);
    
    //find intersection of lotto and viking lotto
    cout << "Matching numbers in first two sets: " << endl;
    set_intersection(lotto.begin(),lotto.end(),vikingLotto.begin(),vikingLotto.end(),
                     inserter(d,d.begin()));

    for_each(d.begin(),d.end(),obj);
    
    //find intersection of jackpot and the above
    cout << "Matching numbers in all three sets: " << endl;
    set_intersection(jackpot.begin(),jackpot.end(),d.begin(),d.end(),
                     inserter(e,e.begin())); 
    
    for_each(e.begin(),e.end(),obj); 

}

int RandomGenerator::operator()() {
    int number;
    do {
	number = rand() %high + low;
    } while(find(numbers.begin(), numbers.end(), number) != numbers.end());
    numbers.push_back(number);
    return number;
}

void print(vector<int> input){
    if(input.size() > 0){    
	copy(input.begin(), input.end(), ostream_iterator<int>(cout, " "));
	cout << endl;
    } else {
	cout << "Vector empty!" << endl;
    }

}

void findMatches(vector<int> i1, vector<int> i2, vector<int> output) {
    cout << "finding matches" << endl;
    set_intersection(i1.begin(),i1.end(),i2.begin(),i2.end(), inserter(output,output.begin()));
}

