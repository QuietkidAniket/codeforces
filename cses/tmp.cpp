struct Food{
  int rating;
  string name;
  Food(int rating, int name){ 
    this->rating = rating;
    this->name = name;
  }

  bool operator<(const Food& other) const{
    if(rating == other.rating){
      return name > other.name;
    }else return rating < other.rating;
  }
};


unordered_map<string, int> ftr; //  food : rating
unordered_map<string, string> ftc; // food : cuisine
unordered_map<string, priority_queue<Food>> ctf; // cuisine : {foods}

class FoodRatings {
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n = foods.size();
        for(int i = 0;i < n; i++){
          ftr[foods[i]] = ratings[i];
          ftc[foods[i]] = cuisines[i];
          ctf[cuisines[i]].push(foods[i]);
        }
    }
    
    void changeRating(string food, int newRating) {
      ftr[food] = newRating;
      auto c = ftc[food];
      ctf[c].push_back({newRating, food});
    }
    
    string highestRated(string cuisine) {
      auto best = ctf[cuisine].top();
      while(fts[best.name] != best.rating){
        ctf[cuisine].pop();
        best = ctf[cuisine].top();
      }
      return best.name;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */