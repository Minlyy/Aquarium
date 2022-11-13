/**
 * @file DecorCastle.h
 * @author Minsong Zheng
 *
 *
 */

#include "Items.h"

#ifndef AQUARIUM_DECORCASTLE_H
#define AQUARIUM_DECORCASTLE_H

/**
 * Castle decoration class
 */
class DecorCastle : public Item {
private:

public:
    DecorCastle(Aquarium* aquarium);

    /// Default constructor (disabled)
    DecorCastle() = delete;

    /// Copy constructor (disabled)
    DecorCastle(const DecorCastle &) = delete;

    /// Assignment operator
    void operator=(const DecorCastle &) = delete;

    wxXmlNode* XmlSave(wxXmlNode* node) override;
};

#endif //AQUARIUM_DECORCASTLE_H
