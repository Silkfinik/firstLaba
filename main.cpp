#include <iostream>

int main() {
  int n, k, sum = -1; // инициализируем sum = -1, чтобы в случае деления на 0 вывести сообщение
  std::cout << "\tSum of digits of the natural number N divisible by K\n" << std::endl;
  std::cout << "Enter N: ";
  std::cin >> n;
  std::cout << "Enter K: ";
  std::cin >> k;
  _asm {
    mov ebx, k // закидываем k в ebx
    cmp ebx, 0 // сравниваем ebx с 0
    je loop_end // если ebx = 0, то заканчиваем цикл (он даже не начался xD )
    mov sum, 0 // инициализируем sum = 0
    loop_start: // начало цикла
      mov ecx, 10 // закидываем 10 в ecx
      mov eax, n // закидываем n в eax
      cmp eax, 0 // сравниваем eax с 0
      je loop_end // если eax = 0, то переходим к loop_end
      mov edx, 0 // обнуляем edx
      div ecx // делим eax на ecx, результат в eax, остаток в edx
      mov n, eax // сохраняем результат деления в n
      mov ecx, edx // сохраняем остаток от деления в ecx (последняя цифра числа)
      mov edx, 0 // обнуляем edx
      mov eax, ecx // копируем ecx (последнюю цифра числа) в eax
      div ebx // делим eax (последнюю цифру числа) на ebx, результат в eax, остаток в edx
      mov eax, ecx // возвращаем eax из ecx (последняя цифру числа)
      cmp edx, 0 // сравниваем edx (остаток от деления) с 0
      je sum_add // если остаток равен 0 переходим к метке sum_add
      jmp loop_start // иначе переходим к началу цикла
    sum_add: // метка sum_add
      add sum, eax // прибавляем к sum значение eax (последняя цифра числа)
      jmp loop_start // переходим к началу цикла
    loop_end: // конец цикла
  }
  if (sum == -1) {
    std::cout << "Divide by 0!";
  }
  else {
    std::cout << "Sum: " << sum;
  }
}
