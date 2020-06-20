#include <string>
#include <ctime>
#include <boost/archive/binary_oarchive.hpp>
#include <boost/archive/binary_iarchive.hpp>

using namespace std;

class Record {
private:
	int index;
	time_t timedate;
	int importance; // 0=obsolete 1=normal 2=important
	string label;
	string website;
	string username;
	string password;
	string tel;
	string comment;

	friend class boost::serialization::access;
	template<class Archive>
	void serialize(Archive &ar, const unsigned int version)
	{
		ar & index;
		ar & timedate;
		ar & importance;
		ar & label;
		ar & website;
		ar & username;
		ar & password;
		ar & tel;
		ar & comment;
	}

public:
	Record() :
		index{-1},
		importance{1},
		label{"None"},
		website{"None"},
		username{"None"},
		password{"None"},
		tel{"None"},
		comment{"None\n"}
		{}

	int getIndex() { return index; }
	string getWebsite() { return website; }
	string getUsername() { return username; }
	string getPassword() { return password; }
	string getComment() { return comment; }

	void setIndex(int _index) { index = _index; }
	void setImportance(int _importance) { importance = _importance; }
	void setLabel(string _label) { label = _label; }
	void setWebsite(string _website) { website = _website; }
	void setUsername(string _username) { username = _username; }
	void setPassword(string _password) { password = _password; }
	void setTel(string _tel) { tel = _tel; }
	void setComment(string _comment) { comment = _comment; }
};

