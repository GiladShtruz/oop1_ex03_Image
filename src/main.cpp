#include "Image.h"
#include <iostream>



int main()
{
    // בדיקה: בנאים
    std::cout << "=== Constructor Tests ===\n";
    Image img1(3, 4, Pixel(BLACK)); // תמונה בגובה 3 ורוחב 4, פיקסלים שחורים
    Image img2(5, 2, Pixel(GRAY));  // תמונה בגובה 5 ורוחב 2, פיקסלים אפורים
    Image img3(3, 4);               // תמונה בגובה 3 ורוחב 4, ברירת מחדל לבן
    Image img4;                     // תמונה ריקה

    std::cout << "Image 1:\n" << img1;
    std::cout << "Image 2:\n" << img2;
    std::cout << "Image 3:\n" << img3;
    std::cout << "Image 4:\n" << img4;

    // בדיקה: השוואה
    std::cout << "\n=== Equality Tests ===\n";
    std::cout << "img1 == img3: " << (img1 == img3 ? "True" : "False") << "\n";
    std::cout << "img1 != img2: " << (img1 != img2 ? "True" : "False") << "\n";

    // בדיקה: איחוד
    std::cout << "\n=== Union Test (|) ===\n";
    Image unionImg = img1 | img2;
    std::cout << "Union of img1 and img2:\n" << unionImg;
    // =בדיקה: איחוד
    std::cout << "\n=== Union Test (|=) ===\n";
    Image tempU1 = img1;
    Image tempU2 = img2;
    tempU1 |= tempU2;
    std::cout << "Union= of img1 and img2:\n" << tempU1;

    // =בדיקה: חיתוך
    std::cout << "\n=== Intersection (=&) ===\n";
    Image temp1 = img1;
    Image temp2 = img2;
    temp1 &= temp2;
    std::cout << "Intersection =of img1 and img2:\n" << temp1;

    // בדיקה: חיתוך
    std::cout << "\n=== Intersection Test (&) ===\n";
    Image intersectImg = img1 & img2;
    std::cout << "Intersection of img1 and img2:\n" << intersectImg;

    // בדיקה: חיבור תמונות
    std::cout << "\n=== Concatenation Test (+) ===\n";
    Image concatImg = img1 + img2;
    std::cout << "Concatenation of img1 and img2:\n" << concatImg;

    // בדיקה: תשליל
    std::cout << "\n=== Negation Test (~) ===\n";
    Image negativeImg = ~img1;
    std::cout << "Negative of img1:\n" << negativeImg;

    // בדיקה: הכפלה בסקלר
    std::cout << "\n=== Scaling Test (*) ===\n";
    Image scaledImg = img1 * 2;
    std::cout << "Scaled img1 by 2:\n" << scaledImg;

    // בדיקה: גישה לפיקסלים
    std::cout << "\n=== Pixel Access Test ===\n";
    std::cout << "Pixel at (1, 1) in img1: " << img1(1, 1).getColor() << "\n";
    img1(1, 1) = Pixel(GRAY);
    std::cout << "Updated Pixel at (1, 1) in img1:\n" << img1;

    // בדיקה: השמה
    std::cout << "\n=== Assignment Test ===\n";
    Image assignedImg = img1;
    std::cout << "Assigned img1 to a new image:\n" << assignedImg;

    // סיום
    std::cout << "\n=== Tests Completed ===\n";
    return 0;
}