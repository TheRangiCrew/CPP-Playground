#include <iostream>
#include <random>

using namespace std;

enum Operator {
    ADD,
    SUBTRACT,
    MULTIPLY,
    DIVIDE
};

class Question {
public:

    Question() {
        random_device rd;
        mt19937 mt(rd());

        uniform_int_distribution<int> dist12(1, 12);
        uniform_int_distribution<int> dist4(1, 4);

        this->num1 = dist12(mt);
        this->num2 = dist12(mt);

        switch (dist4(mt)) {
        case 2:
            this->operation = SUBTRACT;
            this->answer = this->num1 - this->num2;
            break;
        case 3:
            this->operation = MULTIPLY;
            this->answer = this->num1 * this->num2;
            break;
        case 4:
            this->operation = DIVIDE;
            this->answer = this->num1 / this->num2;
            break;
        case 1:
        default:
            this->operation = ADD;
            this->answer = this->num1 + this->num2;
            break;
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const Question& obj) {
        string op = "";
        switch (obj.operation) {
        case ADD:
            op = " + ";
            break;
        case SUBTRACT:
            op = " - ";
            break;
        case MULTIPLY:
            op = " x ";
            break;
        case DIVIDE:
            op = " / ";
            break;
        }

        os << obj.num1 << op << obj.num2 << " = ";
        return os;
    }

    double getAnswer() {
        return this->answer;
    }

    bool isCorrect(double answer) {
        return answer == this->answer;
    }

private:

    int num1;
    Operator operation;
    int num2;
    double answer;

};

int main()
{
    const int num_of_questions = 10;
    Question questions[num_of_questions];

    for (int i = 0; i < num_of_questions; i++) {
        questions[i] = Question();
    }

    for (int i = 0; i < num_of_questions; i++) {
        cout << "Question " << i + 1 << endl;
        cout << "-----------" << endl;
        cout << questions[i];

        double answer;
        cin >> answer;

        if (questions[i].isCorrect(answer)) {
            cout << "Correct!";
        }
        else {
            cout << "Incorrect!";
        }
        cout << endl << endl;
    }

    return 0;
}