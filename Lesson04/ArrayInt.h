#ifndef ARRAYINT_H
#define ARRAYINT_H
#include <cassert> // для assert()

class ArrayInt {

private:
	int m_length;
	int* m_data;

public:
	ArrayInt() : m_length(0), m_data(nullptr)
	{ }

	ArrayInt(int length) :
		m_length(length)
	{
		assert(length >= 0);
		if (length > 0)
			m_data = new int[length];
		else
			m_data = nullptr;
	}

	// Функция erase(), которая будет выполнять очитку массива и сбрасывать его длину на 0 (аналог функции clear() в векторах)
	void erase() {
		delete[] m_data;
		// Здесь нам нужно указать m_data значение nullptr, чтобы на выходе не было висячего указателя
			m_data = nullptr;
		m_length = 0;
	}

	//  Функция для возврата длины массива (аналог size())
	int getLength() { return m_length; }

	// Перегрузка оператора индексации [], чтобы иметь доступ к элементам массива
	int& operator[](int index) {
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	// Функция resize изменяет размер массива. Все существующие элементы сохраняются. Процесс медленный
	void resize(int newLength) 
	{
		// Если массив уже нужной длины — return
		if (newLength == m_length)
			return;
		// Если нужно сделать массив пустым — делаем это и затем return
		if (newLength <= 0) {
			erase();
			return;
		}
		// Теперь знаем, что newLength > 0. Выделяем новый массив
		int* data = new int[newLength];
		// Затем нужно разобраться с количеством копируемых элементов в новый массив
		// Нужно скопировать столько элементов, сколько их есть в меньшем из массивов
		if (m_length > 0) {
			int elementsToCopy = (newLength > m_length) ? m_length : newLength;
			// Поочередно копируем элементы
			for (int index = 0; index < elementsToCopy; ++index)
				data[index] = m_data[index];
		}
		// Удаляем старый массив, так как он нам уже не нужен
		delete[] m_data;
		// И используем вместо старого массива новый! Обратите внимание, m_data указывает
		// на тот же адрес, на который указывает наш новый динамически выделенный массив. Поскольку
		// данные были динамически выделенные — они не будут уничтожены, когда выйдут из области видимости
		m_data = data;
		m_length = newLength;
	}

	// Функция insertBefore() для добавления нового элемента в массив
	// (в реализации эта функция очень похожа на resize())
	void insertBefore(int value, int index) 
	{
		// Проверка корректности передаваемого индекса
		assert(index >= 0 && index <= m_length);
		// Создаем новый массив на один элемент больше старого массива
		int* data = new int[m_length + 1];
		// Копируем все элементы до index-а
		for (int before = 0; before < index; ++before)
			data[before] = m_data[before];
		// Вставляем новый элемент в новый массив
		data[index] = value;
		// Копируем все значения после вставляемого элемента
		for (int after = index; after < m_length; ++after)
			data[after + 1] = m_data[after];
		// Удаляем старый массив и используем вместо него новый
		delete[] m_data;
		m_data = data;
		++m_length;
	}

	void push_back(int value) { insertBefore(value, m_length); }

	//
	// Task 1
	// 
	// - Метод для удаления последнего элемента массива (аналог функции pop_back() в векторах)
	void pop_back() 
	{
		// Создаем новый массив на один элемент меньше старого массива
		int* data = new int[m_length - 1];
		// Копируем все элементы до m_length - 1
		for (size_t index = 0; index < m_length - 1; ++index)
			data[index] = m_data[index];		
		// Удаляем старый массив и используем вместо него новый
		delete[] m_data;
		m_data = data;
		--m_length;
	}

	// - Метод для удаления первого элемента массива (аналог pop_front() в векторах)
	void pop_front() 
	{
		// Создаем новый массив на один элемент меньше старого массива
		int* data = new int[m_length - 1];
		// Копируем все элементы в новый массив до m_length - 1, беря из старого от 1 до m_length
		for (size_t index = 0; index < m_length - 1; ++index)
			data[index] = m_data[index + 1];
		// Удаляем старый массив и используем вместо него новый
		delete[] m_data;
		m_data = data;
		--m_length;
	}

	// - Метод для сортировки массива 
	//   Метод быстрой сортировки:
	//      - Выбрать опорный элемент в массиве — часто встречается вариант с центральным элементом.
	//      - Разделить массив на две части следующим образом: 
	//           - все элементы из левой части, которые больше или равны опорному, перекидываем в правую, аналогично, 
	//           - все элементы из правой, которые меньше или равны опорному кидаем в левую часть.
	//  	- В результате предыдущего шага в левой части массива останутся элементы, которые меньше или равны центральному, а в правой — больше либо равны.
	//  	- Рекурсивно повторяем действие для левой и правой части массива.
	void sort() { qsortRecursive(m_data, m_length); }
	// Реализация быстрой сортировки
	void qsortRecursive(int* mas, int size) {
		//Указатели в начало и в конец массива
		int i = 0;
		int j = size - 1;

		//Центральный элемент массива
		int mid = mas[size / 2];

		//Делим массив
		do {
			//Пробегаем элементы, ищем те, которые нужно перекинуть в другую часть
			//В левой части массива пропускаем(оставляем на месте) элементы, которые меньше центрального
			while (mas[i] < mid) {
				i++;
			}
			//В правой части пропускаем элементы, которые больше центрального
			while (mas[j] > mid) {
				j--;
			}

			//Меняем элементы местами
			if (i <= j) {
				int tmp = mas[i];
				mas[i] = mas[j];
				mas[j] = tmp;

				i++;
				j--;
			}
		} while (i <= j);

		//Рекурсивные вызовы, если осталось, что сортировать
		if (j > 0) {
			//"Левый кусок"
			qsortRecursive(mas, j + 1);
		}
		if (i < size) {
			//"Првый кусок"
			qsortRecursive(&mas[i], size - i);
		}
	}

	// - Метод для вывода на экран элементов
	void write()
	{
		for (size_t index = 0; index < m_length; ++index)
			std::cout << m_data[index] << " ";
		std::cout << std::endl;
	}

	~ArrayInt() { delete[] m_data; }
};
#endif