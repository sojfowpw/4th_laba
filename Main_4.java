import java.util.Random;
import java.util.ArrayList;

public class Main_4 {
    static boolean alg_1(int round_number, ArrayList<Boolean> self_choices, ArrayList<Boolean> enemy_choices) { // упор на победу
        Random rand = new Random();
        if (round_number == 0) {
            return false;
        }
        else if (round_number > 100) {
            return false;
        }
        else if (enemy_choices.get(round_number - 1) == false && self_choices.get(round_number - 1) == true) {
            return false;
        }
        else {
            return rand.nextBoolean();
        }
    }

    static boolean alg_2(int round_number, ArrayList<Boolean> self_choices, ArrayList<Boolean> enemy_choices) { // упор на сотрудничество
        if (round_number == 0) {
            return true;
        }
        else if (enemy_choices.get(round_number - 1) == false && self_choices.get(round_number - 1) == true) {
            return false;
        }
        else {
            return true;
        }
    }

    static boolean algRandom() { // рандом
        Random rand = new Random();
        return rand.nextBoolean();
    }

    static void gameAlg_1AndRandom(int number) { // упор на победу + рандом
        int scoreA = 0, scoreB = 0;
        ArrayList<Boolean> choicesA = new ArrayList<>();
        ArrayList<Boolean> choicesB = new ArrayList<>();
        for (int i = 0; i < number; i++) {
            boolean choiceA = alg_1(i, choicesA, choicesB);
            boolean choiceB = algRandom();
            choicesA.add(choiceA);
            choicesB.add(choiceB);
            if (choiceA && choiceB) {
                scoreA += 24;
                scoreB += 24;
            }
            else if (choiceA == true && choiceB == false) {
                scoreB += 20;
            }
            else if(choiceA == false && choiceB == true) {
                scoreA += 20;
            }
            else {
                scoreA += 4;
                scoreB += 4;
            }
        }
        System.out.println("Результат 1 алгоритма: " + scoreA + "\nРезультат рандомного алгоритма: " + scoreB + "\n");
    }

    static void gameAlg_1AndAlg_2(int number) { // упор на победу + упор на сотрудничество
        int scoreA = 0, scoreB = 0;
        ArrayList<Boolean> choicesA = new ArrayList<>();
        ArrayList<Boolean> choicesB = new ArrayList<>();
        for (int i = 0; i < number; i++) {
            boolean choiceA = alg_1(i, choicesA, choicesB);
            boolean choiceB = alg_2(i, choicesB, choicesA);
            choicesA.add(choiceA);
            choicesB.add(choiceB);
            if (choiceA && choiceB) {
                scoreA += 24;
                scoreB += 24;
            }
            else if (choiceA == true && choiceB == false) {
                scoreB += 20;
            }
            else if(choiceA == false && choiceB == true) {
                scoreA += 20;
            }
            else {
                scoreA += 4;
                scoreB += 4;
            }
        }
        System.out.println("Результат 1 алгоритма: " + scoreA + "\nРезультат 2 алгоритма: " + scoreB + "\n");
    }

    static void gameAlg_2AndRandom(int number) { // упор на сотрудничество + рандом
        int scoreA = 0, scoreB = 0;
        ArrayList<Boolean> choicesA = new ArrayList<>();
        ArrayList<Boolean> choicesB = new ArrayList<>();
        for (int i = 0; i < number; i++) {
            boolean choiceA = alg_2(i, choicesA, choicesB);
            boolean choiceB = algRandom();
            choicesA.add(choiceA);
            choicesB.add(choiceB);
            if (choiceA && choiceB) {
                scoreA += 24;
                scoreB += 24;
            }
            else if (choiceA == true && choiceB == false) {
                scoreB += 20;
            }
            else if(choiceA == false && choiceB == true) {
                scoreA += 20;
            }
            else {
                scoreA += 4;
                scoreB += 4;
            }
        }
        System.out.println("Результат 2 алгоритма: " + scoreA + "\nРезультат рандомного алгоритма: " + scoreB + "\n");
    }

    public static void main(String[] args) {
        Random rand = new Random();
        int number = rand.nextInt() % (101) + 100;
        System.out.println("Количество раундов: " + number);
        gameAlg_1AndRandom(number);
        gameAlg_1AndAlg_2(number);
        gameAlg_2AndRandom(number);
    }
}
