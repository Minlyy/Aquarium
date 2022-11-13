/**
 * @file FishBeta.h
 * @author Minsong Zheng
 *
 * Beta fish class
 */

#ifndef AQUARIUM_FISHBETA_H
#define AQUARIUM_FISHBETA_H

#include "Items.h"
#include "Fish.h"

/**
 * Beta fish class
 */
class FishBeta : public Fish
{
private:

public:
    FishBeta(Aquarium* aquarium);

    /// Default constructor (disabled)
    FishBeta() = delete;

    /// Copy constructor (disabled)
    FishBeta(const FishBeta &) = delete;

    /// Assignment operator
    void operator=(const FishBeta &) = delete;

    wxXmlNode* XmlSave(wxXmlNode* node) override;
};

#endif //AQUARIUM_FISHBETA_H
