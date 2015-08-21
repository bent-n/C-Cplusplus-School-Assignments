// Lab 2 Currency Converter
// William Benton Parrish
// 09/02/14
// Section 1

#include <stdio.h>
main()
{
	//Conversion Factors
	const float usdToEur = 0.76;
	const float usdToCad = 1.09;
	const float usdToGbp = 0.61;
	const float usdToAud = 1.08;
	const float usdToBit = 0.0021; //Bitcoin
	//End Conversions
	
	float currencyAmount = 0;

	//Currency Value in USD
	float usdEur = 0;
	float usdCad = 0;
	float usdGbp = 0;
	float usdAud = 0;
	float usdBit = 0;
	
	
	
	printf("\nPlease enter the currency value: " );
	scanf("%f", &currencyAmount);
	
	//USD Conversion
	printf("\nUSD to:\nEUR: %f\nCAD: %f\nGBP: %f\nAUD: %f\nBIT: %f", currencyAmount*usdToEur,currencyAmount*usdToCad,currencyAmount*usdToGbp, currencyAmount*usdToAud,currencyAmount*usdToBit );
	
	//EUR Conversion
	(usdEur = currencyAmount / usdToEur);
	printf("\n\nEUR to:\nUSD: %f\nCAD: %f\nGBP: %f\nAUD: %f\nBIT: %f", usdEur, usdEur*usdToCad,usdEur*usdToGbp,usdEur*usdToAud,usdEur*usdToBit);
	
	//CAD Conversion
	(usdCad = currencyAmount / usdToCad);
	printf("\n\nCAD to:\nUSD: %f\nEUR: %f\nGBP: %f\nAUD: %f\nBIT: %f", usdCad, usdCad*usdToEur,usdCad*usdToGbp,usdCad*usdToAud,usdCad*usdToBit);
	
	//GBP Conversion
	(usdGbp = currencyAmount / usdToGbp);
	printf("\n\nGBP to:\nUSD: %f\nEUR: %f\nCAD: %f\nAUD: %f\nBIT: %f", usdGbp, usdGbp*usdToEur,usdGbp*usdToCad,usdGbp*usdToAud,usdGbp*usdToBit);
	
	//Aud Conversion
	(usdAud = currencyAmount / usdToAud);
	printf("\n\nAUD to:\nUSD: %f\nEUR: %f\nCAD: %f\nGBP: %f\nBIT: %f", usdAud, usdAud*usdToEur,usdAud*usdToCad,usdAud*usdToGbp,usdAud*usdToBit);
	
	//BIT Conversion
	(usdBit = currencyAmount / usdToBit);
	printf("\n\nBIT to:\nUSD: %f\nEUR: %f\nCAD: %f\nGBP: %f\nAUD: %f", usdBit, usdBit*usdToEur,usdBit*usdToCad,usdBit*usdToGbp,usdBit*usdToAud);

	return 0;


}
