#include <stdio.h>

/** \brief Suma de los dos numeros recibidos
 *
 * \param x float   Primer numero recibido
 * \param y float   Segundo numero recibido
 * \return float    Un numero
 *
 */
float CalcularSuma(float x,float y);

/** \brief Resta al valor A por el valor B
 *
 * \param x float   Primer numero recibido
 * \param y float   Segundo numero recibido
 * \return float    Un numero
 *
 */
float CalcularResta(float x, float y);

/** \brief Divide el numero X por el numero Y
 *
 * \param x float   Primer numero recibido
 * \param y float   Segundo numero recibido
 * \return float    Numero ya dividido o
                    0 si la Y es 0
 *
 */
float CalcularDivision(float x, float y);

/** \brief Multiplica el numero X por numero Y
 *
 * \param x float   Primer numero recibido
 * \param y float   Segundo numero recibido
 * \return float    Numero ya multiplicado
 *
 */
float CalcularMultiplicacion(float x, float y);


/** \brief Calcula el factoreo del numero recibido
 *
 * \param xy int    Numero recibido
 * \return int      Numero ya factorizado
 *
 */
int CalcularFactorial(int xy);
