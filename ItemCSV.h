/** 
 * @file   ItemCSV.h
 * @author jrbalsas
 *
 * @date 13 de octubre de 2015, 10:55
 */

#ifndef ITEMCSV_H
#define	ITEMCSV_H

#include <string>

/**Interfaz para objetos convertibles a y desde formato CSV
 * 
 * P.e. "123456;El ingenioso hidalgo Don Quijote de la Mancha;123"
 */
class ItemCSV {
public:
    virtual std::string toCSV()=0;
    virtual void fromCSV(std::string linea)=0;
private:

};

#endif	/* ITEMCSV_H */

