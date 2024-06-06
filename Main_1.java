import java.util.ArrayList;
import java.util.List;

public class Main_1 {

    static double func(double x) { // функция из условия
        return x * Math.log(x + 1) - 1;
    }

    static double derivativeFunc(double x) { // производная функции
        return Math.log(x + 1) + x / (x + 1);
    }

    static class Result { // класс для хранения промежуточных результатов
        int N;
        double a;
        double b;
        double diff;

        Result(int N, double a, double b, double diff) {
            this.N = N;
            this.a = a;
            this.b = b;
            this.diff = diff;
        }
    }

    static List<Result> halfDivision(double a, double b, double eps) { // метод половинного деления
        List<Result> results = new ArrayList<>();
        int N = 0;
        double x = 0;
        while ((b - a) >= eps) {
            double c = (a + b) / 2;
            results.add(new Result(N, a, b, b - a));
            if (func(c) == 0) {
                break;
            } else if (func(a) * func(c) < 0) {
                b = c;
            } else {
                a = c;
            }
            N++;
            x = c;
        }
        return results;
    }

    static List<Result> newtonMethod(double x0, double eps) { // метод Ньютона
        List<Result> results = new ArrayList<>();
        int N = 0;
        double x1;
        while (Math.abs(func(x0)) >= eps) {
            x1 = x0 - func(x0) / derivativeFunc(x0);
            double diff = Math.abs(x1 - x0);
            if (diff < 0.0001) {
                diff = 0.0001;
            }
            results.add(new Result(N, x0, x1, diff));
            if (diff <= eps) {
                break;
            }
            x0 = x1;
            N++;
        }
        return results;
    }

    static double f(double x) { // функция для метода простых итераций
        if (x < 0.0) {
            return Math.exp(1.0 / x) - 1;
        } else {
            return 1.0 / Math.log(x + 1);
        }
    }

    static List<Result> simpleIterations(double x0, double eps) { // метод простых итераций
        List<Result> results = new ArrayList<>();
        int N = 0;
        double x1;
        while (Math.abs(f(x0)) >= eps) {
            x1 = f(x0);
            if (Math.abs(x1 - x0) < eps) {
                break;
            }
            results.add(new Result(N, x0, x1, Math.abs(x1 - x0)));
            x0 = x1;
            N++;
        }
        return results;
    }

    static void printResults(List<Result> results) { // вывод таблицы результатов
        for (Result result : results) {
            System.out.printf("|%2d|%15.6f|%15.6f|%15.6f|\n", result.N, result.a, result.b, result.diff);
        }
    }

    public static void main(String[] args) {
        double a = -1, b = 1, eps = 0.0001;
        double x0 = -0.5;
        System.out.println("1 корень\n");
        List<Result> halfDivisionResults = halfDivision(a, b, eps);
        printResults(halfDivisionResults);
        System.out.println();
        List<Result> newtonResults = newtonMethod(x0, eps);
        printResults(newtonResults);
        System.out.println();
        List<Result> simpleIterationsResults = simpleIterations(x0, eps);
        printResults(simpleIterationsResults);
        System.out.println("\n");
        System.out.println("2 корень\n");
        a = 0;
        b = 2;
        x0 = 0.5;
        List<Result> halfDivisionResults2 = halfDivision(a, b, eps);
        printResults(halfDivisionResults2);
        System.out.println();
        List<Result> newtonResults2 = newtonMethod(x0, eps);
        printResults(newtonResults2);
        System.out.println();
        List<Result> simpleIterationsResults2 = simpleIterations(x0, eps);
        printResults(simpleIterationsResults2);
    }
}
