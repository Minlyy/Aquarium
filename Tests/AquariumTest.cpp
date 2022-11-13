/**
 * @file AquariumTest.cpp
 * @author Minsong Zheng
 */

#include <pch.h>
#include "gtest/gtest.h"
#include <Aquarium.h>
#include <regex>
#include <string>
#include <fstream>
#include <streambuf>
#include <wx/filename.h>
#include <FishBeta.h>
#include <Magikarp.h>
#include <Buddha.h>
#include <DecorCastle.h>
using namespace std;

const unsigned int RandomSeed = 1238197374;

class AquariumTest : public ::testing::Test {
protected:
    /**
    * Create a path to a place to put temporary files
    */
    wxString TempPath()
    {
        // Create a temporary filename we can use
        auto path = wxFileName::GetTempDir() + L"/aquarium";
        if(!wxFileName::DirExists(path))
        {
            wxFileName::Mkdir(path);
        }

        return path;
    }

    /**
    * Read a file into a wstring and return it.
    * @param filename Name of the file to read
    * @return File contents
    */
    wstring ReadFile(const wxString &filename)
    {
        ifstream t(filename.ToStdString());
        wstring str((istreambuf_iterator<char>(t)),
                istreambuf_iterator<char>());

        return str;
    }

    /**
     * Test to ensure an aquarium .aqua file is empty
     */
    void TestEmpty(wxString filename)
    {
        cout << "Temp file: " << filename << endl;

        auto xml = ReadFile(filename);
        cout << xml << endl;
        ASSERT_TRUE(regex_search(xml, wregex(L"<\\?xml.*\\?>")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<aqua/>")));
    }

    /**
     *  Populate an aquarium with three Beta fish
     */
    void PopulateThreeBetas(Aquarium *aquarium)
    {
        auto fish1 = make_shared<FishBeta>(aquarium);
        fish1->SetLocation(100, 200);
        aquarium->Add(fish1);

        auto fish2 = make_shared<FishBeta>(aquarium);
        fish2->SetLocation(400, 400);
        aquarium->Add(fish2);

        auto fish3 = make_shared<FishBeta>(aquarium);
        fish3->SetLocation(600, 100);
        aquarium->Add(fish3);
    }
    void TestThreeBetas(wxString filename)
    {
        cout << "Temp file: " << filename << endl;

        auto xml = ReadFile(filename);
        cout << xml << endl;

        // Ensure three items
        ASSERT_TRUE(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

        // Ensure the positions are correct
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));

        // Ensure the types are correct
        ASSERT_TRUE(regex_search(xml,
                wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"beta\"/><item.* type=\"beta\"/></aqua>")));
    }
    void PopulateAllTypes(Aquarium *aquarium)
    {
        aquarium->GetRandom().seed(RandomSeed);
        auto fish1 = make_shared<FishBeta>(aquarium);
        fish1->SetLocation(100, 200);
        aquarium->Add(fish1);

        auto fish2 = make_shared<Magikarp>(aquarium);
        fish2->SetLocation(400, 400);
        aquarium->Add(fish2);

        auto fish3 = make_shared<Buddha>(aquarium);
        fish3->SetLocation(600, 100);
        aquarium->Add(fish3);

        auto item1 = make_shared<DecorCastle>(aquarium);
        item1->SetLocation(800, 300);
        aquarium->Add(item1);
    }
    void TestAllTypes(wxString filename)
    {
        cout << "Temp file: " << filename << endl;

        auto xml = ReadFile(filename);
        cout << xml << endl;

        // Ensure three items
        ASSERT_TRUE(regex_search(xml, wregex(L"<aqua><item.*<item.*<item.*</aqua>")));

        // Ensure the positions are correct
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"100\" y=\"200\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"400\" y=\"400\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"600\" y=\"100\"")));
        ASSERT_TRUE(regex_search(xml, wregex(L"<item x=\"800\" y=\"300\"")));

        // Ensure the types are correct
        ASSERT_TRUE(regex_search(xml,
                wregex(L"<aqua><item.* type=\"beta\"/><item.* type=\"magikarp\"/><item.* type=\"buddha\"/><item.* type=\"castle\"/></aqua>")));
    }
    void TestAllTypesSpeed(wxString filename)
    {
        cout << "Temp file: " << filename << endl;

        auto xml = ReadFile(filename);
        cout << xml << endl;
        ASSERT_TRUE(regex_search(xml,
                wregex(L"<item x=\"100\" y=\"200\" SpeedX=\"12\\.3446.*\" SpeedY=\"15\\.3016.*\"")));
        ASSERT_TRUE(regex_search(xml,
                wregex(L"<item x=\"400\" y=\"400\" SpeedX=\"337\\.865.*\" SpeedY=\"347\\.838.*\"")));
        ASSERT_TRUE(regex_search(xml,
                wregex(L"<item x=\"600\" y=\"100\" SpeedX=\"39\\.5853.*\" SpeedY=\"39\\.8769.*\"")));
    }
};

/// Fish filename
const std::wstring FishBetaImageName = L"images/beta.png";

/** Mock class for testing the class Item */
class ItemMock : public Item{
public:
    ItemMock(Aquarium *aquarium) : Item(aquarium, FishBetaImageName) {}

};

TEST_F(AquariumTest, Construct){
    Aquarium aquarium;
}

TEST_F(AquariumTest, HitTest) {
    Aquarium aquarium;

    ASSERT_EQ(aquarium.HitTest(100, 200), nullptr) <<
                                                   L"Testing empty aquarium";

    shared_ptr<ItemMock> fish1 = make_shared<ItemMock>(&aquarium);
    fish1->SetLocation(100, 200);
    aquarium.Add(fish1);

    ASSERT_TRUE(aquarium.HitTest(100, 200) == fish1) <<
                                                     L"Testing fish at 100, 200";

    auto fish2 = make_shared<ItemMock>(&aquarium);
    fish2->SetLocation(100, 200);
    aquarium.Add(fish2);

    ASSERT_EQ(fish2, aquarium.HitTest(100,200));

    ASSERT_EQ(aquarium.HitTest(300, 400), nullptr) <<
                                                   L"Testing empty space with fish";
}

TEST_F(AquariumTest, Save) {
    // Create a path to temporary files
    auto path = TempPath();

    // Create an aquarium
    Aquarium aquarium;

    //
    // First test, saving an empty aquarium
    //
    auto file1 = path + L"/test1.aqua";
    aquarium.Save(file1);

    TestEmpty(file1);

    //
    // Now populate the aquarium
    //

    PopulateThreeBetas(&aquarium);

    auto file2 = path + L"/test2.aqua";
    aquarium.Save(file2);

    TestThreeBetas(file2);

}

TEST_F(AquariumTest, Clear)
{
    auto path = TempPath();
    Aquarium aquarium;
    PopulateThreeBetas(&aquarium);
    //
    //  Test clear function
    //
    aquarium.Clear();
    auto file3 = path + L"/test3.aqua";
    aquarium.Save(file3);

    TestEmpty(file3);
}

TEST_F(AquariumTest, Load)
{
    // Create a path to temporary files
    auto path = TempPath();

    // Create an aquarium
    Aquarium aquarium;
    Aquarium aquarium2;

    //
    // First test, saving an empty aquarium
    //
    auto file1 = path + L"/test1.aqua";
    aquarium.Save(file1);

    TestEmpty(file1);

    aquarium2.Load(file1);
    aquarium2.Save(file1);
    TestEmpty(file1);

    //
    // Now populate the aquarium
    //

    PopulateThreeBetas(&aquarium);

    auto file2 = path + L"/test2.aqua";
    aquarium.Save(file2);

    TestThreeBetas(file2);

    aquarium2.Load(file2);
    aquarium2.Save(file2);
    TestThreeBetas(file2);

    //
    // Test all types
    //
    Aquarium aquarium3;
    PopulateAllTypes(&aquarium3);

    auto file3 = path + L"/test3.aqua";
    aquarium3.Save(file3);

    TestAllTypes(file3);

    aquarium2.Load(file3);
    aquarium2.Save(file3);
    TestAllTypes(file3);
}

TEST_F(AquariumTest, Speed)
{
    // Create a path to temporary files
    auto path = TempPath();

    // Create an aquarium
    Aquarium aquarium;
    PopulateAllTypes(&aquarium);
    auto file = path + L"/test.aqua";
    aquarium.Save(file);
    TestAllTypesSpeed(file);

    aquarium.Clear();
    aquarium.Load(file);

    auto file2 = path + L"/test2.aqua";
    aquarium.Save(file);
    TestAllTypesSpeed(file);
}