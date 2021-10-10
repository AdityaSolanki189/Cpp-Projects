from html.parser import HTMLParser

class MyHTMLParser(HTMLParser):
    def handle_starttag(self, tag, attrs):
        global start_tags
        start_tags.append(tag)
        
    def handle_endtag(self, tag):
        global end_tags
        end_tags.append(tag)

    def handle_data(self, data):
        global all_data
        all_data.append(data)

    def handle_comment(self, data):
        global comments
        comments.append(data)

start_tags = []
end_tags = []
all_data = []
comments = []

parser = MyHTMLParser()

parser.feed('<html><title>TOC Assignment 2</title><body><p>Testing HTML Tags</p></body><!--New Webpage--></html>')

print("\nstart_tags : ", start_tags)

print("end_tags : ", end_tags)

print("data : ", all_data)

print("comments : ", comments)