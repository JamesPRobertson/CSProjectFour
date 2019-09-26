#include <iostream>
#include <vector>
#include <deque>

class Person{
private:
	std::string name;
	std::vector<std::string> * giftList;

public:
	Person():name(""), giftList(nullptr){};

	Person(std::string inputName){
		name = inputName;
		giftList = new std::vector<std::string>();
	}

	std::string getName() const{
		return name;
	}

	std::string getGiftAt(int index) const{
		return giftList->at(index);
	}

	int getGiftListSize(){
		return giftList->size();
	}

	void addGift(std::string input){
		if(!input.empty())
			giftList->push_back(input);
	}
};

void printOut(std::deque<Person> inputQueue);

int main() {
	std::deque<Person> * people = new std::deque<Person>();

	while(true){
		std::string personInput = "";
		std::cout << "Please enter the name of a person" << std::endl;
		std::getline(std::cin, personInput);

		if(!personInput.empty()){
			Person * foo = new Person(personInput);

			//Gift input for current person
			std::string giftInput = "";
			do{
				std::cout << "Please input gifts for: " << foo->getName() << std::endl;
				std::getline(std::cin, giftInput);
				foo->addGift(giftInput);
			}while(!giftInput.empty());

			//Finished gift input so make them wait in the queue
			people->push_front(*foo);
		}
		else{
			break;
		}
	}

	printOut(*people);
}

void printOut(std::deque<Person> peopleQueue){
	std::cout << "Here is the list of everyone: " << std::endl;
	for(Person tempPerson : peopleQueue){
		std::cout << tempPerson.getName() << ":" << std::endl;

		for(int i = 0; i < tempPerson.getGiftListSize(); i++){
			std::cout << "   " << tempPerson.getGiftAt(i) << std::endl;
		}
	}
}