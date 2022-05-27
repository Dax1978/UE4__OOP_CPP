#ifndef ARRAYINT_H
#define ARRAYINT_H
#include <cassert> // ��� assert()

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

	// ������� erase(), ������� ����� ��������� ������ ������� � ���������� ��� ����� �� 0 (������ ������� clear() � ��������)
	void erase() {
		delete[] m_data;
		// ����� ��� ����� ������� m_data �������� nullptr, ����� �� ������ �� ���� �������� ���������
			m_data = nullptr;
		m_length = 0;
	}

	//  ������� ��� �������� ����� ������� (������ size())
	int getLength() { return m_length; }

	// ���������� ��������� ���������� [], ����� ����� ������ � ��������� �������
	int& operator[](int index) {
		assert(index >= 0 && index < m_length);
		return m_data[index];
	}

	// ������� resize �������� ������ �������. ��� ������������ �������� �����������. ������� ���������
	void resize(int newLength) 
	{
		// ���� ������ ��� ������ ����� � return
		if (newLength == m_length)
			return;
		// ���� ����� ������� ������ ������ � ������ ��� � ����� return
		if (newLength <= 0) {
			erase();
			return;
		}
		// ������ �����, ��� newLength > 0. �������� ����� ������
		int* data = new int[newLength];
		// ����� ����� ����������� � ����������� ���������� ��������� � ����� ������
		// ����� ����������� ������� ���������, ������� �� ���� � ������� �� ��������
		if (m_length > 0) {
			int elementsToCopy = (newLength > m_length) ? m_length : newLength;
			// ���������� �������� ��������
			for (int index = 0; index < elementsToCopy; ++index)
				data[index] = m_data[index];
		}
		// ������� ������ ������, ��� ��� �� ��� ��� �� �����
		delete[] m_data;
		// � ���������� ������ ������� ������� �����! �������� ��������, m_data ���������
		// �� ��� �� �����, �� ������� ��������� ��� ����� ����������� ���������� ������. ���������
		// ������ ���� ����������� ���������� � ��� �� ����� ����������, ����� ������ �� ������� ���������
		m_data = data;
		m_length = newLength;
	}

	// ������� insertBefore() ��� ���������� ������ �������� � ������
	// (� ���������� ��� ������� ����� ������ �� resize())
	void insertBefore(int value, int index) 
	{
		// �������� ������������ ������������� �������
		assert(index >= 0 && index <= m_length);
		// ������� ����� ������ �� ���� ������� ������ ������� �������
		int* data = new int[m_length + 1];
		// �������� ��� �������� �� index-�
		for (int before = 0; before < index; ++before)
			data[before] = m_data[before];
		// ��������� ����� ������� � ����� ������
		data[index] = value;
		// �������� ��� �������� ����� ������������ ��������
		for (int after = index; after < m_length; ++after)
			data[after + 1] = m_data[after];
		// ������� ������ ������ � ���������� ������ ���� �����
		delete[] m_data;
		m_data = data;
		++m_length;
	}

	void push_back(int value) { insertBefore(value, m_length); }

	//
	// Task 1
	// 
	// - ����� ��� �������� ���������� �������� ������� (������ ������� pop_back() � ��������)
	void pop_back() 
	{
		// ������� ����� ������ �� ���� ������� ������ ������� �������
		int* data = new int[m_length - 1];
		// �������� ��� �������� �� m_length - 1
		for (size_t index = 0; index < m_length - 1; ++index)
			data[index] = m_data[index];		
		// ������� ������ ������ � ���������� ������ ���� �����
		delete[] m_data;
		m_data = data;
		--m_length;
	}

	// - ����� ��� �������� ������� �������� ������� (������ pop_front() � ��������)
	void pop_front() 
	{
		// ������� ����� ������ �� ���� ������� ������ ������� �������
		int* data = new int[m_length - 1];
		// �������� ��� �������� � ����� ������ �� m_length - 1, ���� �� ������� �� 1 �� m_length
		for (size_t index = 0; index < m_length - 1; ++index)
			data[index] = m_data[index + 1];
		// ������� ������ ������ � ���������� ������ ���� �����
		delete[] m_data;
		m_data = data;
		--m_length;
	}

	// - ����� ��� ���������� ������� 
	//   ����� ������� ����������:
	//      - ������� ������� ������� � ������� � ����� ����������� ������� � ����������� ���������.
	//      - ��������� ������ �� ��� ����� ��������� �������: 
	//           - ��� �������� �� ����� �����, ������� ������ ��� ����� ��������, ������������ � ������, ����������, 
	//           - ��� �������� �� ������, ������� ������ ��� ����� �������� ������ � ����� �����.
	//  	- � ���������� ����������� ���� � ����� ����� ������� ��������� ��������, ������� ������ ��� ����� ������������, � � ������ � ������ ���� �����.
	//  	- ���������� ��������� �������� ��� ����� � ������ ����� �������.
	void sort() { qsortRecursive(m_data, m_length); }
	// ���������� ������� ����������
	void qsortRecursive(int* mas, int size) {
		//��������� � ������ � � ����� �������
		int i = 0;
		int j = size - 1;

		//����������� ������� �������
		int mid = mas[size / 2];

		//����� ������
		do {
			//��������� ��������, ���� ��, ������� ����� ���������� � ������ �����
			//� ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
			while (mas[i] < mid) {
				i++;
			}
			//� ������ ����� ���������� ��������, ������� ������ ������������
			while (mas[j] > mid) {
				j--;
			}

			//������ �������� �������
			if (i <= j) {
				int tmp = mas[i];
				mas[i] = mas[j];
				mas[j] = tmp;

				i++;
				j--;
			}
		} while (i <= j);

		//����������� ������, ���� ��������, ��� �����������
		if (j > 0) {
			//"����� �����"
			qsortRecursive(mas, j + 1);
		}
		if (i < size) {
			//"����� �����"
			qsortRecursive(&mas[i], size - i);
		}
	}

	// - ����� ��� ������ �� ����� ���������
	void write()
	{
		for (size_t index = 0; index < m_length; ++index)
			std::cout << m_data[index] << " ";
		std::cout << std::endl;
	}

	~ArrayInt() { delete[] m_data; }
};
#endif