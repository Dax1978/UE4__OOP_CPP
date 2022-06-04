#include "GenericPlayer.h"

class House : public GenericPlayer
{
public:
	House(const std::string& name = "Дилер");

	// virtual ~House();

	// показывает, хочет ли дилер продолжать брать карты
	// virtual bool IsHitting() const;
	bool IsHitting() const override;

	// переворачивает первую карту
	void FlipFirstCard();
};