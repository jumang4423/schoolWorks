# jsonbin.io usage

1. login

    to make collection or bins, we need to login or signup first.

2. make a COLLECTION

    the definition of collection more like "PROJECT".

    so this time, we should name the collection as "girlcollecter_project" or something like that.

3. make bins in collection that you made previously.

    bins like the dataset.

    for example, if you want to make a todo list dataset, we need to make a bin to get or post data from cloud.

    so in this case, we wanna build a site for collecting cute girls datas which is kinda array of object like this...

```json
[
    {
        "id": 1,
        "img": "imgar.com/sdA30F49FFdd",
        "twiter": "twitter.com/cutegirl1234",
        "title": "i am the cutest girl lol",
        "liked": 992
    }
]
```

    also you can set the bin private or public which means that if you want to connect to the bin and the bin is private, basically you also ned to send Master API key.

4. API calling

    now we made a collection and bins, so next thing to do is comunicating with the frontend javascript and JSONBIN.io actually.

    this is the example of bin API link:

    https://api.jsonbin.io/b/60eedd260cd33f7437c825d5

    you can get data with "GET".

    to update this, use "PUT" after you "GET" the data.
