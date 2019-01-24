#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;



class ProvinceChannelCfg
{
public:
    ProvinceChannelCfg():m_uiChannelId(0),m_uiRate(0),m_uiIndex(0) {cout << "default construct" << endl;}
    ~ProvinceChannelCfg() {}
    
    ProvinceChannelCfg(const ProvinceChannelCfg& c)
    {
        cout << "copy construct" << endl;
        m_uiChannelId = c.m_uiChannelId;
        //m_vecPhone = c.m_vecPhone;
    }
    
    
    ProvinceChannelCfg& operator=(const ProvinceChannelCfg& c)
    {
        cout << "assign operator" << endl;
        // m_uiChannelId = c.m_uiChannelId;
        //m_vecPhone = c.m_vecPhone;
    }

    int m_uiChannelId;
    int m_uiRate;
    vector<string> m_vecPhone;
    int m_uiIndex;
    string m_strPhoneListFilePath;
    string m_strPhoneListFileMd5;
};

typedef map<int, ProvinceChannelCfg> ProvinceChannelCfgMap;
typedef map<int, ProvinceChannelCfg>::iterator ProvinceChannelCfgMapIter;




int main()
{
    map<string, string> m;
    m["111"] = "111-111";

    string s = m["222"];
    cout << "s:" << s << endl;

    map<int, int> mi;
    cout << "x:" << mi[1] << endl;
    
    
    cout << "------------------1-----------------------" << endl;
    
    ProvinceChannelCfg cfg5;
    ProvinceChannelCfg cfg6(cfg5);
    
    cout << "------------------2-----------------------" << endl;
    
    vector<ProvinceChannelCfg> vecProvinceChannelCfg;
    vecProvinceChannelCfg.push_back(cfg5);
    
    
    
    cout << "------------------3-----------------------" << endl;
    
    ProvinceChannelCfgMap m_mapProvinceChannelCfg;
    
    
    ProvinceChannelCfg cfg; // 调用构造函数
    cfg.m_uiChannelId = 1;
    cfg.m_vecPhone.push_back("111"); // 假如此处push大量的数据
    
    m_mapProvinceChannelCfg[cfg.m_uiChannelId] = cfg;  // 调用构造函数、调用赋值操作符
    
    cout << m_mapProvinceChannelCfg[1].m_vecPhone.size() << endl;
    
    
    
    cout << "------------------4-----------------------" << endl;
    
    ProvinceChannelCfg& cfg1 = m_mapProvinceChannelCfg[2];
    cfg1.m_uiChannelId = 1000;
    cout << m_mapProvinceChannelCfg[2].m_uiChannelId << endl;
    
    cout << "------------------5-----------------------" << endl;
    


    return 0;
}

