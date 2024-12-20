#include <vector>
#include "PersonaExc.h"
#include "Persona.h"


Persona::Persona(const Cadena& dni, const Cadena& nombre, const Cadena& apellido, const Fecha& fechaNacimiento, char sexo)
: dni(dni)
{
    setNombre(nombre);
    setApellido(apellido);
    setFechaNacimiento(fechaNacimiento);
    setSexo(sexo);

    cout << "Persona creada" << endl;
}


const Cadena& Persona::getDNI() const
{
    return dni;
}


void Persona::setDNI(const Cadena& dni)
{
    validarDNI(dni);
    this->dni = dni;
}


const Cadena& Persona::getNombre() const
{
    return this->nombre;
}


void Persona::setNombre(const Cadena& nombre)
{
    this->nombre = nombre;
}


const Cadena& Persona::getApellido() const
{
    return apellido;
}


void Persona::setApellido(const Cadena& apellido)
{
    this->apellido = apellido;
}


const Fecha& Persona::getFechaNacimiento() const
{
    return fechaNacimiento;
}


void Persona::setFechaNacimiento(const Fecha& fechaNacimiento)
{
    this->fechaNacimiento = fechaNacimiento;
}


char Persona::getSexo() const
{
    return sexo;
}


void Persona::setSexo(char sexo)
{
    this->sexo = sexo;
}


void Persona::validarDNI(const Cadena& dni)
{
    unsigned longMax = 8;

    if(dni[0] == 'M' || dni[0] == 'F')
    {
        longMax++;
        //TODO: validar que el resto de la cadena sea numerica
    }
    else
    {
        if(!dni.esEnteroPositivo())
        {
            throw PersonaExc("DNI invalido: " + dni + " no es un numero");
        }
    }


    if(dni.longitud() > longMax)
        throw PersonaExc("DNI invalido: " + dni + " supera la longitud maxima");
}


void Persona::imprimir() const
{
    cout << "DNI: " << dni << endl;
    cout << "Nombre: " << nombre << endl;
    cout << "Apellido: " << apellido << endl;
    cout << "Fecha de nacimiento: " << fechaNacimiento << endl;
    cout << "Sexo: " << sexo << endl;
}


ostream& operator<<(ostream& sal, const Persona& persona)
{
    sal
        << persona.getDNI() << '\t'
        << persona.getNombre() << '\t'
        << persona.getApellido() << '\t'
        << persona.getFechaNacimiento() << '\t'
        << persona.getSexo();

    return sal;
}


istream& operator>>(istream& ent, Persona& persona)
{
/*
    Cadena linea;
    ent >> linea;

    vector<Cadena> campos = linea.split('\t');

    if(campos.size() != 5)
        throw PersonaExc("Cantidad de campos incorrecta");

    persona.setDNI(campos[0]);
    persona.setNombre(campos[1]);
    persona.setApellido(campos[2]);
    persona.setFechaNacimiento(campos[3]);
    persona.setSexo(campos[4][0]);
*/  

	string campoStr;

	getline(ent, campoStr, '\t');
    persona.setDNI(campoStr);

	getline(ent, campoStr, '\t');
	persona.setNombre(campoStr);

	getline(ent, campoStr, '\t');
	persona.setApellido(campoStr);

    ent >> persona.fechaNacimiento;
    ent.ignore();
    
	persona.setSexo(ent.get());
	ent.ignore(1);

	return ent;
}
