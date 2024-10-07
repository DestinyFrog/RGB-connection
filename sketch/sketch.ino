
#define PIN_RGB_S0 8
#define PIN_RGB_S1 9
#define PIN_RGB_S2 10
#define PIN_RGB_S3 11
#define PIN_RGB_OUT 12

int
	percent = 1000,

	vermelho,
	verde,
	azul,
	alfa,

	max_vermelho = 203,
	max_verde = 587,
	max_azul = 132,
	max_alfa= 577,

	min_vermelho = 34,
	min_verde = 43,
	min_azul = 12,
	min_alfa = 21;

void setup() {
	Serial.begin(9600);

	pinMode(PIN_RGB_S0, OUTPUT);
	pinMode(PIN_RGB_S1, OUTPUT);
	pinMode(PIN_RGB_S2, OUTPUT);
	pinMode(PIN_RGB_S3, OUTPUT);
	pinMode(PIN_RGB_OUT, INPUT);

	// frequencia 20%
	digitalWrite(PIN_RGB_S0, LOW);
	digitalWrite(PIN_RGB_S1, HIGH);
}

void loop() {
	// vermelho
	digitalWrite(PIN_RGB_S2, LOW);
	digitalWrite(PIN_RGB_S3, LOW);
	vermelho = pulseIn(PIN_RGB_OUT, LOW);

	// azul
	digitalWrite(PIN_RGB_S2, LOW);
	digitalWrite(PIN_RGB_S3, HIGH);
	azul = pulseIn(PIN_RGB_OUT, LOW);

	// alfa
	digitalWrite(PIN_RGB_S2, HIGH);
	digitalWrite(PIN_RGB_S3, LOW);
	alfa = pulseIn(PIN_RGB_OUT, LOW);

	// verde
	digitalWrite(PIN_RGB_S2, HIGH);
	digitalWrite(PIN_RGB_S3, HIGH);
	verde = pulseIn(PIN_RGB_OUT, LOW);

/*
	Serial.println("--------");

	Serial.print( "r: " );
	Serial.print( perc_vermelho );
	Serial.print( "% | " );
	Serial.print( min_vermelho );
	Serial.print( " : " );
	Serial.print( vermelho );
	Serial.print( " : " );
	Serial.println( max_vermelho );

	Serial.print( "g: " );
	Serial.print( perc_verde );
	Serial.print( "% | " );
	Serial.print( min_verde );
	Serial.print( " : " );
	Serial.print( verde );
	Serial.print( " : " );
	Serial.println( max_verde );

	Serial.print( "b: " );
	Serial.print( perc_azul );
	Serial.print( "% | " );
	Serial.print( min_azul );
	Serial.print( " : " );
	Serial.print( azul );
	Serial.print( " : " );
	Serial.println( max_azul );

	Serial.print( "a: " );
	Serial.print( perc_alfa );
	Serial.print( "% | " );
	Serial.print( min_alfa );
	Serial.print( " : " );
	Serial.print( alfa );
	Serial.print( " : " );
	Serial.println( max_alfa );
*/
/*
	double media = vermelho + verde + azul / 3;
	double variancia = pow(vermelho,2) + pow(verde,2) + pow(azul,2) / 3;
	double desvio_padrao = sqrt(variancia);

	Serial.print( "media: " );
	Serial.println( media );

	Serial.print( "variancia: " );
	Serial.println( variancia );

	Serial.print( "desvio padrao: " );
	Serial.println( desvio_padrao );
	*/
/*
	if (perc_vermelho < perc_verde && perc_vermelho < perc_azul)
		Serial.println("vermelho");
	
	else if (perc_verde < perc_vermelho && perc_verde < perc_azul)
		Serial.println("verde");
	
	else if (perc_azul < perc_vermelho && perc_azul < perc_verde)
		Serial.println("azul");
		*/

	Serial.print("{\"r\":");
	Serial.print(vermelho);
	Serial.print(",\"g\":");
	Serial.print(verde);
	Serial.print(",\"b\":");
	Serial.print(azul);
	Serial.print(",\"a\":");
	Serial.print(alfa);
	Serial.println("}");

	delay(150);
}