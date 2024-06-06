import java.util.*;

public class Main_2 {
    static void randdig(ArrayList<Integer> arrdig, int size, int beg, int end_) { // заполнение массива случайными числами
        Random rand = new Random();
        for (int i = 0; i < size; i++) {
            arrdig.add(rand.nextInt(end_ - beg + 1) + beg);
            System.out.print(arrdig.get(i) + " "); // вывод массива
        }
        System.out.println();
    }

    static void newarrfor3(ArrayList<Integer> arrdig_2, ArrayList<Integer> arrdig_3, ArrayList<Integer> newarr, int size) { // заполнение нового массива
        for (int i = 0; i < size; i++) {
            if (i % 2 == 0) {
                newarr.add(arrdig_2.get(i) + arrdig_3.get(i)); // если i - чётное, то сумма
                System.out.print(newarr.get(i) + " ");
            }
            else {
                newarr.add(arrdig_2.get(i) - arrdig_3.get(i)); // иначе - разность
                System.out.print(newarr.get(i) + " ");
            }
        }
    }

    static void leapYear(int beg, int end_) { // високосные года
        for (int i = beg; i <= end_; i++) {
            if (i % 4 == 0) { // если год кратен 4, то он високосный
                System.out.print(i + " ");
            }
        }
    }

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        System.out.print("№1-2\nВведите размер массива: " );
        int size = in.nextInt(); // размер массивов
        ArrayList<Integer> arrdig_1 = new ArrayList<>();
        System.out.print("Исходный массив: ");
        randdig(arrdig_1, size, 100, 200); // заполнение случайными значениями от 100 до 200
        Collections.sort(arrdig_1); // сортировка по возрастанию
        System.out.print("Отсортированный массив: ");
        for (int i : arrdig_1) { // вывод отсортированного массива
            System.out.print(i + " ");
        }
        System.out.println("\n2 по величине элемент: " + arrdig_1.get(size - 2));
        int sum = 0;
        for (int i = 1; i < size - 2; i++) { // сумма элементов между минимальным и 2 по величине
            sum += arrdig_1.get(i);
        }
        System.out.println("Сумма элементов между минимальным и 2 по величине: " + sum + "\n");

        System.out.println("№3");
        ArrayList<Integer> arrdig_2 = new ArrayList<>(); // 1 массив
        ArrayList<Integer> arrdig_3 = new ArrayList<>(); // 2 массив
        System.out.print("Первый массив: ");
        randdig(arrdig_2, size, -50, 50); // заполнение случайными значениями от -50 до 50
        System.out.print("Второй массив: ");
        randdig(arrdig_3, size, -50, 50); // заполнение случайными значениями от -50 до 50
        ArrayList<Integer> newarr = new ArrayList<>(); // новый массив
        System.out.print("Новый массив: ");
        newarrfor3(arrdig_2, arrdig_3, newarr, size); // заполнение нового массива
        System.out.println("\n");

        System.out.println("№4\nИсходный массив: ");
        ArrayList<Integer> arrdigfor4 = new ArrayList<>(); // исходный массив
        randdig(arrdigfor4, size, 100, 200); // заполнение случайными значеними от 100 до 200
        Map<Integer, Integer> countdig = new HashMap<>();
        for (int i : arrdigfor4) {
            countdig.put(i, countdig.getOrDefault(i, 0) + 1); // подсчёт количества
        }
        for (Map.Entry<Integer, Integer> entry : countdig.entrySet()) {
            System.out.println("Число: " + entry.getKey() + " количество повторений: " + entry.getValue());
        }

        System.out.print("\n\n№5\nВвод диапазона лет: ");
        int first_year = in.nextInt(); // переменные для диапазона
        int last_year = in.nextInt();
        leapYear(first_year, last_year); // вывод високосных годов
    }
}
