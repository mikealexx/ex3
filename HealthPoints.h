using std::ostream;

class HealthPoints {

    int m_maxHP;
    int m_hp;
    static const int DEFAULT_MAX_HP = 100;

public:

    /**
     * @brief Construct a new Health Points object with default value 100
     * 
     */
    HealthPoints();

    /**
     * @brief Construct a new Health Points object
     * 
     * @param maxHP Maximum health points of the new object (positive number)
     */
    HealthPoints(const int maxHP);


    /**
     * @brief Construct a new copy Health Points object from another health points object
     * 
     * @param other Other health points object to copy from
     */
    HealthPoints(const HealthPoints& other) = default;

    /**
     * @brief Destroy the Health Points object
     * 
     */
    ~HealthPoints() = default;

    /**
     * @brief Assign to this health points object values from other health points object
     * 
     * @param hp Other health points object to copy values from
     * @return HealthPoints& Updated health points object
     */
    HealthPoints& operator=(const HealthPoints& other) = default;

    /**
     * @brief Add input amount of health points to current health points (can't exceed maximum health points)
     * 
     * @param hp Amount of health points to add
     * @return HealthPoints& Updated health points object
     */
    HealthPoints& operator+=(const int hpToAdd);

    /**
     * @brief Subtract input amount of health points from current health points (can't go lower then 0)
     * 
     * @param hp Amount of health points to subtract
     * @return HealthPoints& Updated health points object
     */
    HealthPoints& operator-=(const int hpToSubtract);

    /**
     * @brief Add two health points objects (addition of their current health points)
     * 
     * @param hp1 First health points object
     * @param hp2 Second health points object
     * @return HealthPoints Temporary health points object with sum of input health points objects
     */
    friend HealthPoints operator+(const HealthPoints& hp, const int hpToAdd);

    /**
     * @brief Subtract two health points objects (subtraction of their current health points)
     * 
     * @param hp1 First health points object
     * @param hp2 Second health points object
     * @return HealthPoints Temporary health points object with difference of input health points objects
     */
    friend HealthPoints operator-(const HealthPoints& hp, const int hpToSubtract);

    /**
     * @brief Check if two health points objects have same amount of current health points
     * 
     * @param hp1 First health points object
     * @param hp2 Second health points object
     * @return true If both health points objects have same amount of health points
     * @return false Otherwise
     */
    friend bool operator==(const HealthPoints& hp1, const HealthPoints& hp2);

    /**
     * @brief Check if two health points objects have different amount of current health points
     * 
     * @param hp1 First health points object
     * @param hp2 Second health points object
     * @return true If both health points objects have same amount of health points
     * @return false Otherwise
     */
    friend bool operator!=(const HealthPoints& hp1, const HealthPoints& hp2);

    /**
     * @brief Check if first health points object has less current health points then the other object
     * 
     * @param hp1 First health points object
     * @param hp2 Second health points object
     * @return true If first health points object has less current health points
     * @return false Otherwise
     */
    friend bool operator<(const HealthPoints& hp1, const HealthPoints& hp2);

    /**
     * @brief Check if first health points object has more current health points then the other object
     * 
     * @param hp1 First health points object
     * @param hp2 Second health points object
     * @return true If first health points object has more current health points
     * @return false Otherwise
     */
    friend bool operator>(const HealthPoints& hp1, const HealthPoints& hp2);

    /**
     * @brief Check if first health points object has less or equal current health points then the other object
     * 
     * @param hp1 First health points object
     * @param hp2 Second health points object
     * @return true If first health points object has less or equal current health points
     * @return false Otherwise
     */
    friend bool operator<=(const HealthPoints& hp1, const HealthPoints& hp2);
    
    /**
     * @brief Check if first health points object has more or equal current health points then the other object
     * 
     * @param hp1 First health points object
     * @param hp2 Second health points object
     * @return true If first health points object has more or equal current health points
     * @return false Otherwise
     */
    friend bool operator>=(const HealthPoints& hp1, const HealthPoints& hp2);

    /**
     * @brief Print health points stats into ostream format: <hp>(<max hp>)
     * 
     * @param os Output stream to print to
     * @param hp health points object to print
     * @return ostream& Returns the updated output stream
     */
    friend ostream& operator<<(ostream& os, const HealthPoints& hp);

    class InvalidArgument {};

private:

    

};

