import struct
import sys
sys.path.append('./proto')

from proxy_pb2 import *
from web_pb2 import *
from player_pb2 import *
from test_pb2 import *
from game_pb2 import *
from base_pb2 import *
from msg_id_pb2 import *
from google.protobuf.json_format import MessageToJson


print("sys", sys.path)

def Encode(msg_id, data):
    send_data = b'S' 
    send_data += (msg_id).to_bytes(4, byteorder="big", signed=False)
    send_data += len(data).to_bytes(4, byteorder="big", signed=False)
    send_data += data
    print("send_data: ", send_data)
    return send_data

def Decode(recv_data):
    msg_signature = recv_data[0:1]
    if msg_signature != b'S':
        print("Error: invalid msg signature")
    msg_id = int.from_bytes(recv_data[1:5], byteorder='big', signed=False)
    length = int.from_bytes(recv_data[5:9], byteorder='big', signed=False)
    data = recv_data[9:]
    # print("Decode recv_data: ", recv_data, " length: ", length, " msg_id: ", msg_id, "data: ", data)
    return msg_id, length, data