Graph Library

ספריית גרף זו מאפשרת ניהול וביצוע פעולות שונות על גרפים בצורה נוחה ופשוטה.

מחלקת Graph
כותרות של פונקציות ציבוריות:
void loadGraph(const std::vector<std::vector<int>> &graph);
טוענת את הגרף הנתון.

void const printGraph() const;
מדפיסה את הגרף.

std::vector<std::vector<int>> getGraph() const;
מחזירה את הגרף הנוכחי.

bool getSymmetricMat() const;
בודקת אם הגרף סימטרי.

bool getWeighted() const;
בודקת אם הגרף מכיל משקלים.

void error(const Graph &other);
מטפלת בשגיאות במקרה של פעולות לא תקינות.

size_t countEdges() const;
סופרת את מספר הקשתות בגרף.

אופרטורים:

Graph &operator*=(const double scalar);
מכפיל את כל ערכי הגרף בסקלר.

Graph &operator*=(const Graph &other);
מכפיל את הגרף הנוכחי בגרף אחר.

Graph &operator+=(const Graph &other);
מחבר את הגרף הנוכחי עם גרף אחר.

Graph operator+(const Graph &other);
מחזיר גרף חדש שהינו תוצאה של חיבור שני גרפים.

Graph &operator+();
מחזיר את הגרף הנוכחי.

Graph operator*(const Graph &other);
מחזיר גרף חדש שהינו תוצאה של הכפלת שני גרפים.

Graph &operator/=(const double scalar);
מחלק את כל ערכי הגרף בסקלר.

Graph operator-(const Graph &other);
מחזיר גרף חדש שהינו תוצאה של חיסור שני גרפים.

Graph &operator-();
מחזיר את הגרף הנוכחי.

Graph &operator-=(const Graph &other);
מחסר את הגרף הנוכחי עם גרף אחר.

Graph &operator++();
מגדיל את כל ערכי הגרף ב-1.

Graph &operator--();
מקטין את כל ערכי הגרף ב-1.

bool operator==(const Graph &other) const;
בודק אם שני הגרפים שווים.

bool operator!=(const Graph &other) const;
בודק אם שני הגרפים אינם שווים.

bool isSubmatrix(const std::vector<std::vector<int>> &A, const std::vector<std::vector<int>> &B) const;
בודק אם מטריצה A היא תת-מטריצה של מטריצה B.

bool operator<(const Graph &other) const;
בודק אם הגרף הנוכחי קטן מגרף אחר.

bool operator<=(const Graph &other) const;
בודק אם הגרף הנוכחי קטן או שווה לגרף אחר.

bool operator>(const Graph &other) const;
בודק אם הגרף הנוכחי גדול מגרף אחר.

bool operator>=(const Graph &other) const;
בודק אם הגרף הנוכחי גדול או שווה לגרף אחר.