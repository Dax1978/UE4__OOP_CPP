#include "GenericPlayer.h"

class House : public GenericPlayer
{
public:
	House(const std::string& name = "�����");

	// virtual ~House();

	// ����������, ����� �� ����� ���������� ����� �����
	// virtual bool IsHitting() const;
	bool IsHitting() const override;

	// �������������� ������ �����
	void FlipFirstCard();
};