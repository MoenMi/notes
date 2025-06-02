import main3
from fastapi.testclient import TestClient

client = TestClient(main3.app)

def test_fixedquery1():
    response = client.get("/items/", params={"q": "fixedquery"})
    assert response.status_code == 200
    data = response.json()
    assert "items" in data
    assert data["q"] == "fixedquery"

def test_fixedquery2():
    response = client.get("/items/", params={"q": "random query"})
    assert response.status_code == 200
    data = response.json()
    assert "items" in data
    assert data["q"] == "fixedquery"
    
# def test_fixedquery1():
#     assert main3.read_items(q='fixedquery') == {'items': [{"item_id": "Foo"}, {"item_id": "Bar"}], 'q': 'fixedquery'}

# def test_fixedquery2():
#     assert main3.read_items(q='fiasdasdxedquery')
