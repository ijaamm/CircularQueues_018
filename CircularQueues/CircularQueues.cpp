#include <iostream>
using namespace std;

class queues {
	int FRONT, REAR, max = 5;
	int queue_array[5];

public:
	queues() {
		FRONT = -1;
		REAR = -1;
	}

	void insert() {
		int num;
		cout << "Enter a Number : ";
		cin >> num;
		cout << endl;

		//cek apakah antrian penuh
		if ((FRONT == 0 && REAR == max - 1) || (FRONT == REAR + 1)) {
			cout << "\nQueues overflow\n";
			return;
		}

		//cek apakah antrian kosong 
		if (FRONT == -1) {
			REAR == 0;
		}
		else {
			//jika rear berada di posisi terakhir array, kembali ke awal array
			if (REAR == max - 1)
				REAR = 0;
			else
				REAR = REAR + 1;
		}
		queue_array[REAR] = num;
	}

	void remove() {
		//cek apakah antrian kosong
		if (FRONT == -1) {
			cout << "Queue underflow\n";
			return;
		}
		cout << "\nThe element deleted from the queue is : " << queue_array[FRONT] << "\n";
		//cek jika antrian hanya memiliki 1 element 
		if (FRONT == REAR) {
			FRONT = -1;
			REAR = -1;
		}
		else {
			//jika element yang di hapus berada di posisi terakhir array kembali ke awal array
			if (FRONT == max - 1)
				FRONT = 0;
			else
				FRONT = FRONT + 1;
		}
	}

	void display() {
		int FRONT_position = FRONT;
		int REAR_position = REAR;

		//cek apakah antrian kosong 
		if (FRONT == -1) {
			cout << "Queue is empty\n";
			return;
		}

		cout << "\nelement in queue are : \n";

		//jika front_posision <= rear position, iterasi dari front hingga rear
		if (FRONT_position <= REAR_position) {
			while (FRONT_position <= REAR_position) {
				cout << queue_array[FRONT_position] << "  ";
				FRONT_position++;
			}
			cout << endl;
		}
		else {
			//jika front_position > rear_position, iterasi dari frontn hingga akhir array
			while (FRONT_position <= max - 1) {
				cout << queue_array[FRONT_position] << "  ";
				FRONT_position++;
			}

			FRONT_position = 0;

			//iterasi dari awal array hingga rear
			while (FRONT_position <= REAR_position) {
				cout << queue_array[FRONT_position] << "  ";
				FRONT_position++;
			}
			cout << endl;
		}
	}
};

int main() {
	queues q;
	char ch;

	while (true) {
		try {
			cout << "Menu" << endl;
			cout << "1. implement insert operation" << endl;
			cout << "2. implement delete operation" << endl;
			cout << "3. display values" << endl;
			cout << "4. exit" << endl;
			cout << "enter your choise (1-4): ";
			cin >> ch;
			cout << endl;

			switch (ch) {
			case '1': {
				q.insert();
				break;
			}
			case '2': {
				q.remove();
				break;
			}
			case '3': {
				q.display();
				break;
			}
			case '4': {
				return 0;
			}
			default: {
				cout << "invalid option!!" << endl;
				break;
			}
			}
		}
		catch (exception& e) {
			cout << "check for the velues entered." << endl;
		}
	}
	return 0;
}