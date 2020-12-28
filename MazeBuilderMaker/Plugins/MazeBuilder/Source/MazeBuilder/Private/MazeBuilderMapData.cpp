#include "MazeBuilderMapData.h"

FMazeBuilderMapData::FMazeBuilderMapData()
{
}

FMazeBuilderMapData::~FMazeBuilderMapData()
{
}

FString FMazeBuilderMapData::ToString()
{
	FString str;
	for (int i = 0; i < strokeMap.Num(); i++)
	{
		str.Append(strokeMap[i]->ToString());
	}
	return str;
}

void FMazeBuilderMapData::Clear()
{
	strokeMap.Empty();
	max_row = 0;
	max_col = 0;
	min_row = 0;
	min_col = 0;
	MAX_LEVEL = 1;
}

/**
* 游戏运行时获取地块信息
*
* @参数 pos 为二维坐标位置
*/
TSharedPtr<FMazeBuilderStrokeInfo> FMazeBuilderMapData::GetStrokeInfoAt(FIntPoint pos)
{
	if(pos.X>=0&&pos.Y>=0&&pos.X<max_col&&pos.Y<max_row) return strokeMap[pos];
	return NULL;
}

/**
* 地块编辑器编辑替换时使用
*
* @参数 pos 为二维坐标位置
*/
AMazeBuilderBrushTemplate* FMazeBuilderMapData::GetStrokeAt(FIntPoint pos)
{
	TSharedPtr<FMazeBuilderStrokeInfo> stroke_info = GetStrokeInfoAt(pos);
	if (stroke_info != NULL) return stroke_info->obj;
	return NULL;
}

void FMazeBuilderMapData::AddStrokeInfo(FIntPoint pos,TSharedPtr<FMazeBuilderStrokeInfo> stroke)
{
	//TSharedPtr<FMazeBuilderStrokeInfo> oldStroke = GetStrokeInfoAt(pos);
	//if (oldStroke != nullptr) strokeMap.Remove(pos); 
	strokeMap.Add(pos,stroke);// Add本身就会覆盖相同键的值
}

/**
* 获取地块上的原始块的名称,便于计算衍生地块名
*
* @参数 pos 为二维坐标位置
*/
FString FMazeBuilderMapData::GetOldStrokeName(FIntPoint pos)
{
	FString oldStrokeName = "0";
	AMazeBuilderBrushTemplate* oldStrokeObj = GetStrokeAt(pos);
	if(oldStrokeObj) oldStrokeName = FMazeBuilderUltility::GetStrokeCode(oldStrokeObj->name);
	return oldStrokeName;
}

/**
* 从表中读取地图信息
*
*/

void FMazeBuilderMapData::ReadMapData(AActor mapRoot)
{
	strokeMap.Empty();
	FWorldContext worldContext = GEditor->GetEditorWorldContext();
	UWorld *world = (&worldContext)->World();
	if (world == NULL) return;
	ULevel *level = world->GetCurrentLevel();
	if (level == NULL) return;
	FString levelName = level->GetName();
	TArray<FString> OutTextArray;
	//string sceneName = SceneManager.GetActiveScene().name;
	bool loadSuccess = FMazeBuilderUltility::LoadTextToArray(levelName + "_mapData.txt", OutTextArray);
	if (loadSuccess)
	{
		// 这里处理表格数据，暂不处理
	}
	/*
	FString savePath = Application.dataPath + "/MapEditor/" + sceneName + "_mapData.txt";
	FileInfo fi = new FileInfo(savePath);
	FileStream fs = fi.Open(FileMode.OpenOrCreate);
	StreamReader sr = new StreamReader(fs);
	while (sr.Peek() >= 0)
	{
		string strLine = sr.ReadLine();
		//Utility.DebugText(strLine);
		// 重构Map信息
		string[] strs = strLine.Split('\t');
		STROKE_INFO stroke = new STROKE_INFO(strs[0], strs[1].ToInt(), strs[2].ToInt());
		stroke.row = strs[3].ToInt();
		stroke.col = strs[4].ToInt();
		stroke.path = new PATH_INFO(strs[6].ToInt() == 1, strs[7].ToInt() == 1, strs[8].ToInt() == 1, strs[9].ToInt() == 1);
		max_col = Mathf.Max(stroke.col, max_col);
		max_row = Mathf.Max(stroke.row, max_row);
		min_col = min_col == 0 ? stroke.col : Mathf.Min(min_col, stroke.col);
		min_row = min_row == 0 ? stroke.row : Mathf.Min(min_row, stroke.row);
		Vector3 pos = new Vector3(strs[5].ToFloat(), strs[6].ToFloat(), strs[7].ToFloat());
		Transform target = null;
		for (int i = 0; i < mapRoot.transform.childCount; i++)
		{
			Transform child = mapRoot.transform.GetChild(i);
			if (child.position == pos && child.name == strs[8])
			{
				target = child;
				break;
			}
		}
		if (target)
		{
			stroke.obj = target.gameObject;
			int lv = strs[8].Length;
			if (lv >= MAX_LEVEL) MAX_LEVEL = lv;
		}
		else
		{
			Utility.DebugText(strs[8] + "@[" + strs[5] + "," + strs[6] + "," + strs[7] + "]找不到");
		}
		this.strokeTable.Add(stroke);
	}
	sr.Dispose();
	sr.Close();
	*/
}

void FMazeBuilderMapData::SaveMapData()
{

	//保存表格数据
	/*
	EditorSceneManager.SaveScene(SceneManager.GetActiveScene());
	string sceneName = SceneManager.GetActiveScene().name;
	string savePath = Application.dataPath + "/MapEditor/" + sceneName + "_mapData.txt";
	Utility.DebugText(savePath);
	FileInfo fi = new FileInfo(savePath);
	FileStream fs = fi.Open(FileMode.Create);
	StreamWriter sw = new StreamWriter(fs);
	sw.Write(ToString());
	sw.Dispose();
	sw.Close();
	*/
}

/*
[ExecuteAlways]
public class MapData : MonoBehaviour {
	public static MapData instance;
	public MAP_DATA mapData = new MAP_DATA();

	void Awake()
	{
		instance = this;
		mapData.ReadMapData(this.gameObject);
		Utility.DebugText(mapData.MAX_LEVEL);
	}

	// Use this for initialization
	void Start() {
		SceneManager.sceneUnloaded += OnSceneUnLoaded;
	}

	// Update is called once per frame
	void Update() {

	}

	private void OnEnable() {
		SceneManager.sceneLoaded += OnSceneLoaded;
	}

	private void OnSceneLoaded(Scene scene, LoadSceneMode mode)
	{
#if UNITY_EDITOR
		mapData.ReadMapData(this.gameObject);
#endif
	}

	private void OnSceneUnLoaded(Scene scene)
	{
#if UNITY_EDITOR

#endif
	}
	*/