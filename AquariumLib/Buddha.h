/**
 * @file Buddha.h
 * @author Minsong Zheng
 *
 * Buddha fish class
 */

#ifndef AQUARIUM_BUDDHA_H
#define AQUARIUM_BUDDHA_H

#include "Items.h"
#include "Fish.h"

/**
 * Buddha fish class
 */
class Buddha : public Fish
{
private:

public:
    Buddha(Aquarium* aquarium);

    /// Default constructor (disabled)
    Buddha() = delete;

    /// Copy constructor (disabled)
    Buddha(const Buddha &) = delete;

    /// Assignment operator
    void operator=(const Buddha &) = delete;

    wxXmlNode* XmlSave(wxXmlNode* node) override;
};

#endif //AQUARIUM_BUDDHA_H
