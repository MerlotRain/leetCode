# 倒排索引(Inverted Index)


常规的索引是文档到关键词的映射，就是每个文档指向一个它所包含的索引项的序列，也就是文档文档指向了它包含的索引项序列，也就是文档指向它包含的哪些单词。

倒排索引也叫反向索引。是文档检索系统中最常用的数据结构。被用来存储在全文搜索下某个单词在一个文档或者一组文档中的存储位置的映射。
常被应用于搜索引擎和关键字查询的问题中。比如文档检索系统中，查询哪些文件包含了某个单词。

而反向索引则是单词(关键词)指向包含了它的文档们。比如：

```
T0 = "it is what it is"
T1 = "what is it"
T2 = "it is a banana"
```

得到的反向文件索引是：

```
"a":      {2}
"banana": {2}
"is":     {0, 1, 2}
"it":     {0, 1, 2}
"what":   {0, 1}
```

当我们以”what” “is” “it”检索条件去查询时，结果集是：{0,1}∩{0,1,2}∩{0,1,2} = {0,1} 。  
也就是结果集为文档0和文档1，但其实精确匹配的是文档1。


### 数据结构

- 将文章提炼关键词，且每个关键词都对应这篇文章
- 在加入新文章时，我们需要为新文章中的关键词索引和之前的合并


### 应用场景

* mysql中的索引实现，使用 B+ 树实现
* ES
* 推荐内容召回





### 参考

[Elasticsearch](https://github.com/elastic/elasticsearch) 就是使用倒排索引(inverted index)的结构来做快速的全文搜索; ElasticSearch 不仅用于全文搜索, 还有非常强大的统计功能 (facets),携程，58，美团的分享中都提到ES构建实时日志系统，帮助定位系统问题。


[Elasticsearch权威指南](http://es.xiaoleilu.com/index.html)


