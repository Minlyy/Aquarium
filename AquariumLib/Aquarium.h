/**
 * @file Aquarium.h
 * @author Minsong Zheng
 *
 * The Aquarium
 */

#ifndef AQUARIUMAPP_CPP_AQUARIUM_H
#define AQUARIUMAPP_CPP_AQUARIUM_H

#include<memory>
#include"Items.h"
#include <random>

/**
 * The Aquarium
 */
class Aquarium {
private:
    std::unique_ptr<wxBitmap> mBackground;  ///< Background image to use
    /// All of the items to populate our aquarium
    std::vector<std::shared_ptr<Item>> mItems;
    void XmlItem(wxXmlNode* node);
    /// Random number generator
    std::mt19937 mRandom;

public:
    void OnDraw(wxDC* dc);

    Aquarium();

    void Add(std::shared_ptr<Item> item);

    std::shared_ptr<Item> HitTest(int x, int y);

    void toFront(std::shared_ptr<Item> grabbedItem);

    void Save(const wxString& filename);

    void Load(const wxString& filename);

    void Clear();

    void Update(double elapsed);

    /**
     * Get the random number generator
     * @return Pointer to the random number generator
     */
    std::mt19937 &GetRandom() {return mRandom;}

    /**
     * Get the width of the aquarium
     * @return Aquarium width in pixels
     */
    int GetWidth() const { return mBackground->GetWidth(); }

    /**
     * Get the height of the aquarium
     * @return Aquarium height in pixels
     */
    int GetHeight() const { return mBackground->GetHeight(); }
};

#endif //AQUARIUMAPP_CPP_AQUARIUM_H
