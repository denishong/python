#include <stdio.h>

struct Dashboard {
	int speed;
	char fuel;
	float mileage;
	int engineTemp;
	int rpm;
};

int main()
{
	struct Dashboard d1;

	d1.speed = 80;
	d1.fuel = 'F';
	d1.mileage = 5821.44287;
	d1.engineTemp = 200;
	d1.rpm = 1830;

	printf("Speed: %dkm/h\n", d1.speed);
   printf("Fuel: %c\n", d1.fuel);
   printf("Mileage: %fkm\n", d1.mileage);
   printf("Engine temp: %d℃\n", d1.engineTemp);
   printf("RPM: %d\n", d1.rpm);

    return 0;
}
