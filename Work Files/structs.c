#define WHITE 1
#define BLUE  2
#define PINK  3
#define GREEN 4

struct apt{			/* apt is the tag */
	int MBedroom;		/* Members */
	int Bedroom;
	int Den;
	float Bath;
	double MBath;
}Duplex[2] = {{BLUE, BLUE, GREEN, WHITE, WHITE},
	      {PINK, BLUE, BLUE, GREEN, GREEN} };




int main(int argc, char *argv[])
{
	

	printf("My Bedroom: %d\n",	Duplex[0].MBedroom);
	printf("Bedroom: %d\n",		Duplex[0].Bedroom);

	PaintApt(Duplex[0], WHITE);

	printf("My Bedroom: %d\n",	Duplex[0].MBedroom);
	printf("Bedroom: %d\n",		Duplex[0].Bedroom);


}	

struct apt PaintApt(struct apt Target, int Color)
{
	Target.MBedroom = Color;
	Target.Bedroom = Color;
}