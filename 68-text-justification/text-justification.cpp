class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> result;
    vector<string> line_buffer;
    int line_length = 0;

    for (const string& word : words) {
        if (line_length + word.length() + line_buffer.size() <= maxWidth) {
            line_buffer.push_back(word);
            line_length += word.length();
        } else {
            string line;
            int spaces_needed = maxWidth - line_length;
            if (line_buffer.size() == 1) {
                line += line_buffer[0] + string(spaces_needed, ' ');
            } else {
                int space_per_gap = spaces_needed / (line_buffer.size() - 1);
                int extra_spaces = spaces_needed % (line_buffer.size() - 1);
                line += line_buffer[0];
                for (int i = 1; i < line_buffer.size(); ++i) {
                    line += string(space_per_gap + (i <= extra_spaces ? 1 : 0), ' ');
                    line += line_buffer[i];
                }
            }
            result.push_back(line);
            line_buffer.clear();
            line_buffer.push_back(word);
            line_length = word.length();
        }
    }

    string last_line = line_buffer[0];
    for (int i = 1; i < line_buffer.size(); ++i) {
        last_line += ' ' + line_buffer[i];
    }
    last_line += string(maxWidth - last_line.length(), ' ');
    result.push_back(last_line);

    return result;
    }
};